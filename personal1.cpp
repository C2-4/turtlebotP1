#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>

int main(int argc, char** argv)
{

  //init the ROS node
  ros::init(argc, argv, "personal2");
  ros::NodeHandle nh;

  //init publisher
  ros::Publisher cmd_vel_pub_;
  cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1);

  //init direction that turtlebot should go

  geometry_msgs::Twist base_cmd;
  geometry_msgs::Twist base_cmd_turn_left;

  base_cmd.linear.x = 0;
  base_cmd.linear.y = 0;
  base_cmd.angular.z = 0;

  base_cmd_turn_left.linear.x = 0;
  base_cmd_turn_left.linear.y = 0;
  base_cmd_turn_left.angular.z = 0;

  //and let's go forward by setting X to a positive value
  base_cmd.linear.x = 0.55;
  base_cmd.angular.z = 0.0;

  ros::Rate rate(50); // 50Hz

  while(nh.ok()) { //have we ctrl + C?  If no... keep going!
    //"publish" sends the command to turtlebot to keep going

    //go forward for 2 seconds

    for(int n=140; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = - 1.57/2; //45 deg/s

    for(int n=85; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

    for(int n=14; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = 1.57/2; //-45 deg/s

    for(int n=95; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

    for(int n=35; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

    for(int n=85; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

    for(int n=14; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = - 1.57/2; //30 deg/s * 2 sec = 60 degrees

    for(int n=85; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

    for(int n=140; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

    base_cmd_turn_left.linear.x = 0;
    base_cmd_turn_left.angular.z = - 1.57/2;

    for(int n=188; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

  base_cmd.linear.x = 0;
  base_cmd.linear.y = 0;
  base_cmd.angular.z = 0;
  cmd_vel_pub_.publish(base_cmd);
  break;
}
  ROS_INFO("Finished\n");

  return 0;
}

/*

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "math.h"

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "personal");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);

  for (size_t i = 0; i < 1; i++) {

    ros::Duration(1.0).sleep();

    geometry_msgs::Twist msg;

    msg.linear.x = 1.0;
    msg.angular.z = 0.0;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.0).sleep();

for (int i = 0 ; i < 10 ; i++) {
    msg.linear.x = 1.0;
    msg.angular.z = M_PI / 4;
    cmd_vel_pub.publish(msg);

    ros::Duration(0.1).sleep();
  }
    msg.linear.x = 1.5;
    msg.angular.z =  - M_PI / 4;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.0).sleep();

    msg.linear.x = 0.5;
    msg.angular.z = 0.0;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.linear.x = 1.5;
    msg.angular.z = -M_PI / 4;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.0).sleep();

    msg.linear.x = 1.0;
    msg.angular.z =  M_PI / 4;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.angular.z = 0.0;
    msg.linear.x = 0.8;
    cmd_vel_pub.publish(msg);

    ros::Duration(0.5).sleep();
  }


  return 0;
}

*/
