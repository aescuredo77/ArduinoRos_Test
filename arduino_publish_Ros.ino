/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";
int Potenciometro=0;
int light=0;
int sound=0;
char msgstring[128];
void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  sensores();
  str_msg.data = msgstring;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}

void sensores()
{
  Potenciometro=analogRead(A0);
  light=analogRead(A6);
  sound=analogRead(A2);
  sprintf(msgstring,"%d,%d,%d, Arduino grove Beginner Kit ",Potenciometro,light,sound);
}
