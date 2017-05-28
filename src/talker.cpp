#include <performance_tests/talker.h>

namespace performance_tests
{
Talker::Talker(ros::NodeHandle nh): message_("hello")
{
    dynamic_reconfigure::Server<performance_tests::performanceTestsConfig>::CallbackType cb;
    cb= boost::bind(&Talker::configCallback,this, _1, _2);
    dr_srv_.setCallback(cb);
    int rate;

    ros::NodeHandle pnh("~");
    pnh.param("message", message_, message_);
    pnh.param("rate", rate,1);

    pub_=nh.advertise<performance_tests::SuperAwesome>("topicsome",1);
    timer_=nh.createTimer(ros::Duration(1/rate), &Talker::timerCallback,this);
}
void Talker::timerCallback(const ros::TimerEvent &event)
{
    performance_tests::SuperAwesome msg;
    msg.message=message_;
    pub_.publish(msg);
}
void Talker::configCallback(performance_tests::performanceTestsConfig &config, uint32_t level)
{
    message_=config.message.c_str();
}
}
