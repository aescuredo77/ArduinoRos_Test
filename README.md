# ArduinoRos_Test

## Previus installation ##

Manually install the ros_lib.h library on the Arduino, https://www.arduinolibraries.info/libraries/rosserial-arduino-library

- sudo apt-get install ros-noetic-rosserial-arduino

## Usage ## 

- From a terminal (step 1): roscore
- From another terminal (step 2):  rosrun rosrun rosserial_python serial_node.py /dev/ttyUSB0
- From another terminal (step 3):  rosrun beginner_tutorials subscriber_arduino.py


### Frist Test ###

Load in  the arduino board the program "arduino_publish_Ros.ino"

We group the information from the sensors in a string and send it to the ros environment and from there a module separates it and publishes it in several posts. Or to see how to do it in the most comfortable way.

- Arduino connection module :Step 2 creates a serial connection with the Arduino and generates the /serial_node node and the /chatter and /diagnostics topic. In /chatter we send the information from the Arduino as a String.

- Arduino translator module: Step 3 subscribes to /chatter to receive the Arduino info and generates the listener node and the topics /poten /light /sound, where the integer values of the potentiometer, light sensor and microphone are published respectively.
 


### Second Test ###

Load in  the arduino board the program "arduino_publish_subscribe_Ros.ino"

The only difference with the previous one is the Arduino code and sending the commands. A trivial thing that has taken me hours. Because std_msgs/String is not a String to use and when trying to compare 

- in_msg.data == "togle_led" there was no way, although it entered that
- To solve this issue:

```ruby
   String p;
   ...
   // in the function
   p=in_msg.dat;
   if (p == "togle_led"){
   ...
   
 ```  

#### Instruction to send command 

- rostopic pub /input_arduino std_msgs/String test_buzzer -once


