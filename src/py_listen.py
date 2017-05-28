#!/usr/bin/env python

import rospy

from performance_tests.msg import SuperAwesome

def callback(data):
    '''
    Callback function for the subscriber.
    '''
    # Simply print out values in our custom message.
    rospy.loginfo(rospy.get_name() + " I heard %s", data.message)

def listener():
    '''
    Main function.
    '''
    # Create a subscriber with appropriate topic, custom message and name of
    # callback function.
    rospy.Subscriber('topicsome', SuperAwesome, callback)
    # Wait for messages on topic, go to callback function when new messages
    # arrive.
    rospy.spin()

# Main function.
if __name__ == '__main__':
    # Initialize the node and name it.
    rospy.init_node('py_listen')
    # Go to the main loop.
    listener()
