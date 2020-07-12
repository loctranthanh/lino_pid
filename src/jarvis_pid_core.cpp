#include "jarvis_pid/jarvis_pid_core.h"

JarvisPID::JarvisPID()
{
}

JarvisPID::~JarvisPID()
{
}

void JarvisPID::publishMessage(ros::Publisher *pub_message)
{
  jarvis_msgs::PID msg;
  msg.p = p_;
  msg.d = d_;
  msg.i = i_;
  pub_message->publish(msg);
}

void JarvisPID::messageCallback(const jarvis_msgs::PID::ConstPtr &msg)
{
  p_ = msg->p;
  d_ = msg->d;
  i_ = msg->i;

  //echo P,I,D
  ROS_INFO("P: %f", p_);
  ROS_INFO("D: %f", d_);
  ROS_INFO("I: %f", i_);
}

void JarvisPID::configCallback(jarvis_pid::jarvisPIDConfig &config, double level)
{
  //for PID GUI
  p_ = config.p;
  d_ = config.d;
  i_ = config.i;

}
