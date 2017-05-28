#ifndef PERFORMANCE_TESTS_LISTENER_H
#define PERFORMANCE_TESTS_LISTENER_H

#include <ros/ros.h>
#include <ros/time.h>

#include <performance_tests/SuperAwesome.h>

namespace performance_tests
{
  class Listener
  {
  public:
      explicit Listener(ros::NodeHandle nh);
      void messageCallback(const performance_tests::SuperAwesome::ConstPtr &msg);

  private:
      ros::Subscriber sub_;
  };
}
#endif
