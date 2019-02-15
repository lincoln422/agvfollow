#include <ros.h>
#include "MeOrion.h"
#include "SoftwareSerial.h"
#include <Wire.h>
#include <geometry_msgs/Twist.h>


//MeEncoderNew motor1(0x09, SLOT1); 
//MeEncoderNew motor2(0x09, SLOT2); 
//MeEncoderNew motor3(0x0a, SLOT1); 
//MeEncoderNew motor4(0x0a, SLOT2);


#define DEFAULTSPEED 100

int moveSpeed =DEFAULTSPEED;




int motor1speed = moveSpeed;
int motor2speed = moveSpeed;
int motor3speed = moveSpeed;
int motor4speed = moveSpeed;
   


ros::NodeHandle nh ;

void velMessageReceived ( const geometry_msgs::Twist& msg ) {
    motor1speed=-moveSpeed*(msg.linear.y-msg.linear.x+0.42*msg.angular.z);
  motor2speed=-moveSpeed*(msg.linear.y+msg.linear.x-0.42*msg.angular.z);
  motor3speed=moveSpeed*(msg.linear.y-msg.linear.x-0.42*msg.angular.z);
  motor4speed=moveSpeed*(msg.linear.y+msg.linear.x+0.42*msg.angular.z);
  //motor1.runSpeed(motor1speed,0);
  //motor2.runSpeed(motor2speed,0);
  //motor3.runSpeed(motor3speed,0);
  //motor4.runSpeed(motor4speed,0);

}

// Create a subscri ber obj ect .
ros::Subscriber<geometry_msgs::Twist> sub("speed_vel", &velMessageReceived );

void setup()
{   

 // motor1.begin();
//motor2.begin();
//motor3.begin();
//motor4.begin();

  //Serial.begin(9600);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
