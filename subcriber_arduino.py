#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from std_msgs.msg import Int16

potx = rospy.Publisher('poten', Int16, queue_size=10)
lightx = rospy.Publisher('light', Int16, queue_size=10)
soundx = rospy.Publisher('sound',Int16, queue_size=10)

def callback(data):
    global potx,lightx,soundx
    rospy.loginfo("%s", data.data)
    datilla =  data.data
    msg1 = datilla.split(",")
       
    potx.publish(int(msg1[0]))
    lightx.publish(int(msg1[1]))
    soundx.publish(int(msg1[2]))

  
    
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.


    rospy.init_node('listener', anonymous=False)
        
    rospy.Subscriber("out_arduino", String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':

    listener()
