#!/usr/bin/env python

import rospy

from dynamic_reconfigure.server import Server as DynamicReconfigureServer

from performance_tests.msg import SuperAwesome
from performance_tests.cfg import performanceTestsConfig as ConfigType

class PerformanceTests(object):
    '''
    Performance Tests class.
    '''
    def __init__(self):
        # Get the private namespace parameters from command line or launch file.
        init_message = rospy.get_param('~message', 'hello')
        rate = float(rospy.get_param('~rate', '1.0'))
        rospy.loginfo('rate = %f', rate)
        # Create a dynamic reconfigure server.
        self.server = DynamicReconfigureServer(ConfigType, self.reconfigure_cb)
        # Create a publisher for our custom message.
        self.pub = rospy.Publisher('topicsome', SuperAwesome, queue_size=1)
        # Initialize message variables.
        self.message = init_message

        # Create a timer to go to a callback. This is more accurate than
        # sleeping for a specified time.
        rospy.Timer(rospy.Duration(1 / rate), self.timer_cb)

        # Allow ROS to go to all callbacks.
        rospy.spin()

    def timer_cb(self, _event):
        """
        Called at a specified interval. Publishes message.
        """
        # Set the message to publish as our custom message.
        msg = SuperAwesome()
        # Fill in custom message variables with values updated from dynamic
        # reconfigure server.
        msg.message = self.message
        # Publish our custom message.
        self.pub.publish(msg)

    def reconfigure_cb(self, config, dummy):
        '''
        Create a callback function for the dynamic reconfigure server.
        '''
        # Fill in local variables with values received from dynamic reconfigure
        # clients (typically the GUI).
        self.message = config["message"]
        # Return the new variables.
        return config

# Main function.
if __name__ == '__main__':
    # Initialize the node and name it.
    rospy.init_node('py_talk')
    # Go to class functions that do all the heavy lifting. Do error checking.
    try:
        PerformanceTests()
    except rospy.ROSInterruptException:
        pass
