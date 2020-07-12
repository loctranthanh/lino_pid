#ifndef SR_JARVIS_PID_CORE_H
#define SR_JARVIS_PID_CORE_H

#include "ros/ros.h"
#include "ros/time.h"

// Custom message includes. Auto-generated from msg/ directory.
#include <jarvis_msgs/PID.h>

// Dynamic reconfigure includes.
#include <dynamic_reconfigure/server.h>
// Auto-generated from cfg/ directory.
#include <jarvis_pid/jarvisPIDConfig.h>

class JarvisPID
{
public:
  JarvisPID();
  ~JarvisPID();
  void configCallback(jarvis_pid::jarvisPIDConfig &config, double level);
  void publishMessage(ros::Publisher *pub_message);
  void messageCallback(const jarvis_msgs::PID::ConstPtr &msg);

  double p_;
  double d_;
  double i_;

};
#endif
