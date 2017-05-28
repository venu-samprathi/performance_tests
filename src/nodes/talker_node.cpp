#include <performance_tests/talker.h>

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;

  performance_tests::Talker node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
}
