#include <ros/ros.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Float32.h>
#include <dynamic_reconfigure/server.h>
#include <stroll_bearnav/distanceConfig.h>
#include <stroll_bearnav/Speed.h>


using namespace std;

ros::Publisher dist_pub_;
ros::Publisher distEvent_pub_;
ros::Subscriber odometrySub;
ros::Publisher speed_pub_;
nav_msgs::Odometry odometry;
std_msgs::Float32 dist_;
std_msgs::Float32 distEvent_;
double pointDist=0;
float totalDist=0;
double startx,starty,currentx,currenty,pointx,pointy;
float distanceEvent=0;
double diffM=0;
bool start=true;
stroll_bearnav::distanceConfig config;
stroll_bearnav::Speed speed;
float distanceThreshold=1;


void callback(stroll_bearnav::distanceConfig &config, uint32_t level) {

	 distanceThreshold=config.distance_param;
 	 ROS_INFO("Reconfigure Request: %f", 
            config.distance_param);
}

void odomcallback(const nav_msgs::Odometry::ConstPtr& msg){
	if(start){
		pointx=msg->pose.pose.position.x;
		pointy=msg->pose.pose.position.y;
		start=false;	
	}	
	currentx=msg->pose.pose.position.x;
	currenty=msg->pose.pose.position.y;
	pointDist = sqrt(pow(currentx-pointx,2)+pow(currenty-pointy,2));
   
	
	if(pointDist+diffM>distanceThreshold){
		totalDist+=pointDist+diffM;
		diffM=pointDist+diffM-distanceThreshold;
		pointx=currentx;
		pointy=currenty;
		distanceEvent=totalDist;
		distEvent_.data=distanceEvent;
		distEvent_pub_.publish(distEvent_);
		
 		dist_.data=totalDist;
	}  else {
		dist_.data=totalDist+pointDist+diffM;
	}
	dist_pub_.publish(dist_);
	speed.distance=totalDist;
	speed.forwardSpeed=msg->twist.twist.linear.x;
	speed.angularSpeed=msg->twist.twist.linear.y;
	speed.flipper=msg->twist.twist.angular.y;
	speed_pub_.publish(speed);
	
}



int main(int argc, char** argv)
{ 
  ros::init(argc, argv, "distance");
  ros::NodeHandle nh_;
  dynamic_reconfigure::Server<stroll_bearnav::distanceConfig> server;
  dynamic_reconfigure::Server<stroll_bearnav::distanceConfig>::CallbackType f;
  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  odometrySub = nh_.subscribe<nav_msgs::Odometry>("/odom",10 ,odomcallback);
  dist_pub_=nh_.advertise<std_msgs::Float32>("/distance",1);
  distEvent_pub_=nh_.advertise<std_msgs::Float32>("/event/meter",1);
  speed_pub_=nh_.advertise<stroll_bearnav::Speed>("/speed/data",1);
  ros::spin();
  return 0;
}

