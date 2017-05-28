Purpose: Check the performance of combination of CPP and Py Nodes.

Used dynamic reconfigure to provide on the fly changing of rate at which nodes are published

- talker and listener are CPP nodes
- py_talk and py_loisten are python nodes

Please do the following:
1)build the package
2) run roscore
3) before launching any of the nodes we need to set the availability of statistics by doing the following:
rosparam set enable_statistics true
4) Launch any of the node files(except tools.launch as it will be automatically launched with any of the launch files)
5) rosrun rqt_gui rqt_gui
6) enable topic monitor plugin and make sure the topic and statistics boxes are checked
7) enable the plugin that shows the graph depicting all the nodes. you should be able to see the topic communication frequency
8) Feel free to change the message publishing rate of publisher nodes as follows:

rosrun performance_tests py_talk.py _message:="python here" _rate:=100
The above will set the publishing rate of python publisher

9) You may choose to launch all the nodes using all_nodes.launch and view how all the nodes are performing


