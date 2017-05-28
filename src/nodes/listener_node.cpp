#include <performance_tests/listener.h>

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;

  performance_tests::Listener node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
} 
