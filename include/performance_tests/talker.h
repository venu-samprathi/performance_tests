#ifndef PERFORMANCE_TESTS_TALKER_H
#define PERFORMANCE_TESTS_TALKER_H

#include <ros/ros.h>
#include <ros/time.h>

#include <performance_tests/SuperAwesome.h>

#include <dynamic_reconfigure/server.h>
#include <performance_tests/performanceTestsConfig.h>

namespace performance_tests
{
class Talker
{
public:
    explicit Talker(ros::NodeHandle nh);
    void configCallback(performance_tests::performanceTestsConfig &config, uint32_t level);
    void timerCallback(const ros::TimerEvent &event);
 private:
    ros::Timer timer_;
    ros::Publisher pub_;
    dynamic_reconfigure::Server<performance_tests::performanceTestsConfig> dr_srv_;
    std::string message_;
};
}
#endif
