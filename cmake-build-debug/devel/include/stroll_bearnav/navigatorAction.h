// Generated by gencpp from file stroll_bearnav/navigatorAction.msg
// DO NOT EDIT!


#ifndef STROLL_BEARNAV_MESSAGE_NAVIGATORACTION_H
#define STROLL_BEARNAV_MESSAGE_NAVIGATORACTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <stroll_bearnav/navigatorActionGoal.h>
#include <stroll_bearnav/navigatorActionResult.h>
#include <stroll_bearnav/navigatorActionFeedback.h>

namespace stroll_bearnav
{
template <class ContainerAllocator>
struct navigatorAction_
{
  typedef navigatorAction_<ContainerAllocator> Type;

  navigatorAction_()
    : action_goal()
    , action_result()
    , action_feedback()  {
    }
  navigatorAction_(const ContainerAllocator& _alloc)
    : action_goal(_alloc)
    , action_result(_alloc)
    , action_feedback(_alloc)  {
  (void)_alloc;
    }



   typedef  ::stroll_bearnav::navigatorActionGoal_<ContainerAllocator>  _action_goal_type;
  _action_goal_type action_goal;

   typedef  ::stroll_bearnav::navigatorActionResult_<ContainerAllocator>  _action_result_type;
  _action_result_type action_result;

   typedef  ::stroll_bearnav::navigatorActionFeedback_<ContainerAllocator>  _action_feedback_type;
  _action_feedback_type action_feedback;





  typedef boost::shared_ptr< ::stroll_bearnav::navigatorAction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::stroll_bearnav::navigatorAction_<ContainerAllocator> const> ConstPtr;

}; // struct navigatorAction_

typedef ::stroll_bearnav::navigatorAction_<std::allocator<void> > navigatorAction;

typedef boost::shared_ptr< ::stroll_bearnav::navigatorAction > navigatorActionPtr;
typedef boost::shared_ptr< ::stroll_bearnav::navigatorAction const> navigatorActionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::stroll_bearnav::navigatorAction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace stroll_bearnav

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'stroll_bearnav': ['/home/kevin/jaguar_ws/src/stroll_bearnav/msg', '/home/kevin/jaguar_ws/src/stroll_bearnav/cmake-build-debug/devel/share/stroll_bearnav/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::stroll_bearnav::navigatorAction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::stroll_bearnav::navigatorAction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::stroll_bearnav::navigatorAction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "53791ea4fe02864da09f85448437ff32";
  }

  static const char* value(const ::stroll_bearnav::navigatorAction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x53791ea4fe02864dULL;
  static const uint64_t static_value2 = 0xa09f85448437ff32ULL;
};

template<class ContainerAllocator>
struct DataType< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "stroll_bearnav/navigatorAction";
  }

  static const char* value(const ::stroll_bearnav::navigatorAction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
navigatorActionGoal action_goal\n\
navigatorActionResult action_result\n\
navigatorActionFeedback action_feedback\n\
\n\
================================================================================\n\
MSG: stroll_bearnav/navigatorActionGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
navigatorGoal goal\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: stroll_bearnav/navigatorGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal definiton\n\
int32 traversals\n\
\n\
================================================================================\n\
MSG: stroll_bearnav/navigatorActionResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
navigatorResult result\n\
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalStatus\n\
GoalID goal_id\n\
uint8 status\n\
uint8 PENDING         = 0   # The goal has yet to be processed by the action server\n\
uint8 ACTIVE          = 1   # The goal is currently being processed by the action server\n\
uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing\n\
                            #   and has since completed its execution (Terminal State)\n\
uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)\n\
uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due\n\
                            #    to some failure (Terminal State)\n\
uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,\n\
                            #    because the goal was unattainable or invalid (Terminal State)\n\
uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing\n\
                            #    and has not yet completed execution\n\
uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,\n\
                            #    but the action server has not yet confirmed that the goal is canceled\n\
uint8 RECALLED        = 8   # The goal received a cancel request before it started executing\n\
                            #    and was successfully cancelled (Terminal State)\n\
uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be\n\
                            #    sent over the wire by an action server\n\
\n\
#Allow for the user to associate a string with GoalStatus for debugging\n\
string text\n\
\n\
\n\
================================================================================\n\
MSG: stroll_bearnav/navigatorResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#result definition\n\
bool success\n\
\n\
================================================================================\n\
MSG: stroll_bearnav/navigatorActionFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
navigatorFeedback feedback\n\
\n\
================================================================================\n\
MSG: stroll_bearnav/navigatorFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
float32 distance\n\
float32 diffRot\n\
int32[] histogram\n\
int32 max\n\
int32 correct\n\
int32 outliers\n\
int32 keypoints_avg\n\
int32 matches\n\
int32[] stats\n\
\n\
";
  }

  static const char* value(const ::stroll_bearnav::navigatorAction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_goal);
      stream.next(m.action_result);
      stream.next(m.action_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct navigatorAction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::stroll_bearnav::navigatorAction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::stroll_bearnav::navigatorAction_<ContainerAllocator>& v)
  {
    s << indent << "action_goal: ";
    s << std::endl;
    Printer< ::stroll_bearnav::navigatorActionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.action_goal);
    s << indent << "action_result: ";
    s << std::endl;
    Printer< ::stroll_bearnav::navigatorActionResult_<ContainerAllocator> >::stream(s, indent + "  ", v.action_result);
    s << indent << "action_feedback: ";
    s << std::endl;
    Printer< ::stroll_bearnav::navigatorActionFeedback_<ContainerAllocator> >::stream(s, indent + "  ", v.action_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // STROLL_BEARNAV_MESSAGE_NAVIGATORACTION_H
