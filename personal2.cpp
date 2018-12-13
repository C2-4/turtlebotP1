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

    for(int n=130; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = - 1.57/2; //45 deg/s

    for(int n=85; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

    for(int n=35; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = 1.57/2; //-45 deg/s

    for(int n=90; n>0; n--) {
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

    for(int n=35; n>0; n--) {
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
