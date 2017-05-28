#include <performance_tests/listener.h>

namespace performance_tests
{
Listener::Listener(ros::NodeHandle nh)
{
    sub_=nh.subscribe("topicsome",1, &Listener::messageCallback, this);
}
void Listener::messageCallback(const performance_tests::SuperAwesome::ConstPtr &msg)
{
    ROS_INFO("message is %s ", msg->message.c_str());
}
}
