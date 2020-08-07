//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the stroll_bearnav package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __stroll_bearnav__FEATUREEXTRACTIONCONFIG_H__
#define __stroll_bearnav__FEATUREEXTRACTIONCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace stroll_bearnav
{
  class featureExtractionConfigStatics;

  class featureExtractionConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(featureExtractionConfig &config, const featureExtractionConfig &max, const featureExtractionConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const featureExtractionConfig &config1, const featureExtractionConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, featureExtractionConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const featureExtractionConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, featureExtractionConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const featureExtractionConfig &config) const = 0;
      virtual void getValue(const featureExtractionConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T featureExtractionConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (featureExtractionConfig::* field);

      virtual void clamp(featureExtractionConfig &config, const featureExtractionConfig &max, const featureExtractionConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const featureExtractionConfig &config1, const featureExtractionConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, featureExtractionConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const featureExtractionConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, featureExtractionConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const featureExtractionConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const featureExtractionConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, featureExtractionConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, featureExtractionConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<featureExtractionConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(featureExtractionConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("targetKeypoints"==(*_i)->name){targetKeypoints = boost::any_cast<int>(val);}
        if("maxLine"==(*_i)->name){maxLine = boost::any_cast<double>(val);}
        if("thresholdParam"==(*_i)->name){thresholdParam = boost::any_cast<int>(val);}
        if("adaptThreshold"==(*_i)->name){adaptThreshold = boost::any_cast<bool>(val);}
        if("featureOvershootRatio"==(*_i)->name){featureOvershootRatio = boost::any_cast<double>(val);}
        if("optimized"==(*_i)->name){optimized = boost::any_cast<bool>(val);}
        if("detector"==(*_i)->name){detector = boost::any_cast<int>(val);}
        if("descriptor"==(*_i)->name){descriptor = boost::any_cast<int>(val);}
      }
    }

    int targetKeypoints;
double maxLine;
int thresholdParam;
bool adaptThreshold;
double featureOvershootRatio;
bool optimized;
int detector;
int descriptor;

    bool state;
    std::string name;

    
}groups;



//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int targetKeypoints;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double maxLine;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int thresholdParam;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool adaptThreshold;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double featureOvershootRatio;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool optimized;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int detector;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int descriptor;
//#line 228 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("featureExtractionConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const featureExtractionConfig &__max__ = __getMax__();
      const featureExtractionConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const featureExtractionConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const featureExtractionConfig &__getDefault__();
    static const featureExtractionConfig &__getMax__();
    static const featureExtractionConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const featureExtractionConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void featureExtractionConfig::ParamDescription<std::string>::clamp(featureExtractionConfig &config, const featureExtractionConfig &max, const featureExtractionConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class featureExtractionConfigStatics
  {
    friend class featureExtractionConfig;

    featureExtractionConfigStatics()
    {
featureExtractionConfig::GroupDescription<featureExtractionConfig::DEFAULT, featureExtractionConfig> Default("Default", "", 0, 0, true, &featureExtractionConfig::groups);
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.targetKeypoints = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.targetKeypoints = 5000;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.targetKeypoints = 500;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("targetKeypoints", "int", 0, "Desired number of keypoints", "", &featureExtractionConfig::targetKeypoints)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("targetKeypoints", "int", 0, "Desired number of keypoints", "", &featureExtractionConfig::targetKeypoints)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.maxLine = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.maxLine = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.maxLine = 0.5;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<double>("maxLine", "double", 0, "Last line to extract features from", "", &featureExtractionConfig::maxLine)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<double>("maxLine", "double", 0, "Last line to extract features from", "", &featureExtractionConfig::maxLine)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.thresholdParam = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.thresholdParam = 10000;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.thresholdParam = 400;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("thresholdParam", "int", 0, "Response detector threshold", "", &featureExtractionConfig::thresholdParam)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("thresholdParam", "int", 0, "Response detector threshold", "", &featureExtractionConfig::thresholdParam)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.adaptThreshold = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.adaptThreshold = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.adaptThreshold = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<bool>("adaptThreshold", "bool", 0, "Adaptive threshold", "", &featureExtractionConfig::adaptThreshold)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<bool>("adaptThreshold", "bool", 0, "Adaptive threshold", "", &featureExtractionConfig::adaptThreshold)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.featureOvershootRatio = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.featureOvershootRatio = 300.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.featureOvershootRatio = 30.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<double>("featureOvershootRatio", "double", 0, "Feature overshoot percentage", "", &featureExtractionConfig::featureOvershootRatio)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<double>("featureOvershootRatio", "double", 0, "Feature overshoot percentage", "", &featureExtractionConfig::featureOvershootRatio)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.optimized = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.optimized = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.optimized = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<bool>("optimized", "bool", 0, "Separate detection and description", "", &featureExtractionConfig::optimized)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<bool>("optimized", "bool", 0, "Separate detection and description", "", &featureExtractionConfig::optimized)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.detector = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.detector = 3;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.detector = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("detector", "int", 0, "Image feature detector", "{'enum_description': 'Detector type', 'enum': [{'srcline': 15, 'description': 'AGAST', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'AGAST'}, {'srcline': 16, 'description': 'SURF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'SURf'}, {'srcline': 17, 'description': 'upSURF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'upSURf'}]}", &featureExtractionConfig::detector)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("detector", "int", 0, "Image feature detector", "{'enum_description': 'Detector type', 'enum': [{'srcline': 15, 'description': 'AGAST', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'AGAST'}, {'srcline': 16, 'description': 'SURF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'SURf'}, {'srcline': 17, 'description': 'upSURF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'upSURf'}]}", &featureExtractionConfig::detector)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.descriptor = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.descriptor = 2;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.descriptor = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("descriptor", "int", 0, "Image feature descriptor", "{'enum_description': 'Descriptor type', 'enum': [{'srcline': 20, 'description': 'BRIEF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'BRIEF'}, {'srcline': 21, 'description': 'SURF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'SURF'}]}", &featureExtractionConfig::descriptor)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(featureExtractionConfig::AbstractParamDescriptionConstPtr(new featureExtractionConfig::ParamDescription<int>("descriptor", "int", 0, "Image feature descriptor", "{'enum_description': 'Descriptor type', 'enum': [{'srcline': 20, 'description': 'BRIEF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'BRIEF'}, {'srcline': 21, 'description': 'SURF', 'srcfile': '/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'SURF'}]}", &featureExtractionConfig::descriptor)));
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(featureExtractionConfig::AbstractGroupDescriptionConstPtr(new featureExtractionConfig::GroupDescription<featureExtractionConfig::DEFAULT, featureExtractionConfig>(Default)));
//#line 366 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<featureExtractionConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<featureExtractionConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<featureExtractionConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    featureExtractionConfig __max__;
    featureExtractionConfig __min__;
    featureExtractionConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const featureExtractionConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static featureExtractionConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &featureExtractionConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const featureExtractionConfig &featureExtractionConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const featureExtractionConfig &featureExtractionConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const featureExtractionConfig &featureExtractionConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<featureExtractionConfig::AbstractParamDescriptionConstPtr> &featureExtractionConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<featureExtractionConfig::AbstractGroupDescriptionConstPtr> &featureExtractionConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const featureExtractionConfigStatics *featureExtractionConfig::__get_statics__()
  {
    const static featureExtractionConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = featureExtractionConfigStatics::get_instance();

    return statics;
  }

//#line 15 "/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg"
      const int featureExtraction_AGAST = 1;
//#line 16 "/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg"
      const int featureExtraction_SURf = 2;
//#line 17 "/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg"
      const int featureExtraction_upSURf = 3;
//#line 20 "/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg"
      const int featureExtraction_BRIEF = 1;
//#line 21 "/home/kevin/jaguar_ws/src/stroll_bearnav/cfg/featureExtraction.cfg"
      const int featureExtraction_SURF = 2;
}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __FEATUREEXTRACTIONRECONFIGURATOR_H__
