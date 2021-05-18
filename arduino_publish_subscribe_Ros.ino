/*
 * rosserial Publisher and subscriber example
 * Publish the state of the sensors 
 * and subscribe the status of actuator
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;


std_msgs::String str_msg, in_msg;
ros::Publisher chatter("out_arduino", &str_msg);
int buzzer = 5;
int led =4;
int Potenciometro=0;
int light=0;
int sound=0;
char msgstring[128];
String p;
void messageCb(std_msgs::String& in_msg){
    p=in_msg.data;
    chatter.publish(&in_msg);
    if(p == "togle_led") digitalWrite(led, HIGH-digitalRead(led));
    else if (p == "test_buzzer"){
      tone(buzzer, Potenciometro); // Send 1KHz sound signal...
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(1000);
    }
}
ros::Subscriber<std_msgs::String> sub("input_arduino", &messageCb );
void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led,HIGH);
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  digitalWrite(led,LOW);
  delay(1000);
}

void loop()
{
  sensores();
  str_msg.data = msgstring;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(300);
}

void sensores()
{
  Potenciometro=analogRead(A0);
  light=analogRead(A6);
  sound=analogRead(A2);
  sprintf(msgstring,"%d,%d,%d, Arduino grove Beginner Kit ",Potenciometro,light,sound);
}
