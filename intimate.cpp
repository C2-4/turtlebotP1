#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  //init the ROS node
  ros::init(argc, argv, "intimate");
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

    for(int n=150; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = - 1.57/2; //45 deg/s

    for(int n=75; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = 1.57/2; //-45 deg/s

    for(int n=80; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

    for(int n=35; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

    for(int n=75; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }

  base_cmd_turn_left.linear.x = 0.5;
  base_cmd_turn_left.angular.z = - 1.57/2; //30 deg/s * 2 sec = 60 degrees

    for(int n=75; n>0; n--) {
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






/* void Avoid_distance_A () {
  ros::NodeHandle nh;

  ros::Publisher cmd_vel_pub_;
  cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1);
  geometry_msgs::Twist base_cmd;
  ros::Rate rate(50); // 50Hz

  int Velocity[]={0, -1.57/2, 1.57/2, 0, 1.57/2, -1.57/2};
  int Loops[]={150, 75, 80, 35, 75, 75, 100};
  int n;
  while (nh.ok()){
    for (int i=0; i<7; i++){
      base_cmd.linear.x = 0.5;
      base_cmd.linear.y = 0;
      base_cmd.angular.z = Velocity[i];
      n = Loops[i];
      while (n>0){
        cmd_vel_pub_.publish(base_cmd);
        rate.sleep();
        n=n-1;
      }
    }
    base_cmd.linear.x = 0;
    base_cmd.linear.y = 0;
    base_cmd.angular.z = 0;
    cmd_vel_pub_.publish(base_cmd);
    break;
  }
ROS_INFO("Finished\n");
}

int main(int argc, char** argv){
  ros::init(argc, argv, "intimate");
//  ros::init(argc, argv, "distance_A");
//  ro's::NodeHandle nh;

  //ros::Publisher cmd_vel_pub_;
  //cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1);

Avoid_distance_A();

  return 0;
}

*/

/*#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  //init the ROS node
  ROS_INFO_STREAM("Hello World");
  ros::init(argc, argv, "robot_driver");
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
  base_cmd.linear.x = 0.25;
  base_cmd.angular.z = 0.0;
  ROS_INFO_STREAM("And Crashing ... ctrl + c to stop me 🙂");

  //base_cmd_turn_left will be used to turn turtlebot 90 degrees
  base_cmd_turn_left.linear.x = 0; //m/s
  base_cmd_turn_left.angular.z = 1.57/2; //45 deg/s * 2 sec = 90 degrees

  ros::Rate rate(5); // 5Hz

  while(nh.ok()) { //have we ctrl + C?  If no... keep going!
    //"publish" sends the command to turtlebot to keep going

    //go forward for 2 seconds
    for(int n=10; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd);
      rate.sleep();
    }

    //turn 90 degrees (takes 2 seconds)
    for(int n=10; n>0; n--) {
      cmd_vel_pub_.publish(base_cmd_turn_left);
      rate.sleep();
    }
  }


  base_cmd.linear.x = 0;
  base_cmd.linear.y = 0;
  base_cmd.angular.z = 0;
  cmd_vel_pub_.publish(base_cmd);

  ROS_INFO("Finished\n");

  return 0;
}
*/

























/*#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "math.h"

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "intimate");

float pi = 3.1415926;

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 10);

  for (size_t i = 0; i < 1; i++) {

    ros::Duration(1.0).sleep();

    geometry_msgs::Twist msg;

    msg.linear.x = 1.0;
    msg.angular.z = 1.5;
    cmd_vel_pub.publish(msg);

    ros::Duration(5.0).sleep();
/*
    msg.linear.x = 1.0;
    msg.angular.z = 2*pi /5 ;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.linear.x = 1.0;
    msg.angular.z =  - pi / 5;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.0).sleep();

    msg.linear.x = 0.8;
    msg.angular.z = 0.0;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.linear.x = 1.0;
    msg.angular.z = -pi / 5;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.0).sleep();

    msg.linear.x = 1.0;
    msg.angular.z =  pi / 5;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.angular.z = 0.0;
    msg.linear.x = 0.8;
    cmd_vel_pub.publish(msg);

    ros::Duration(0.5).sleep();
    */
//  }


//  return 0;
//}



























/*

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "math.h"
//#include "turtlesim/TeleportAbsolute.h"
//#include "turtlesim/SetPen.h"

int main(int argc, char *argv[]) {
ros::init(argc, argv, "test5");

ros::NodeHandle nh;
ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);
float pi = 3.14159265

  int counter = 1;
    while (counter < 2) {
    ros::Duration(1.5).sleep();

    geometry_msgs::Twist msg;

    msg.angular.z  = pi / 2;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.0).sleep();

    msg.angular.z = 0.0;
    msg.linear.x = 1.2;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.linear.x = 1.0;
    msg.angular.z = - pi / 3;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.angular.z = 0.0;
    msg.linear.x = 2.0;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.linear.x = 1.0;
    msg.angular.z = pi / 3;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.angular.z = 0.0;
    msg.linear.x = 1.0;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.linear.x = 1.0;
    msg.angular.z = pi / 3;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.angular.z = 0.0;
    msg.linear.x = 2.0;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.linear.x = 1.0;
    msg.angular.z = - pi / 3;
    cmd_vel_pub.publish(msg);

    ros::Duration(1.2).sleep();

    msg.angular.z = 0.0;
    msg.linear.x = 1.0;
    cmd_vel_pub.publish(msg);

  ros::Duration(1.2).sleep();

    counter++;
  }


  return 0;
}

/*




























/* #include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <nav_msgs/Odometry.h>

#include <math.h>

geometry_msgs::Pose2D current_pose;
ros::Publisher pub_pose2d;

void odomCallback(const nav_msgs::OdometryConstPtr& msg)
{
    // linear position
    current_pose.x = msg->pose.pose.position.x;
    current_pose.y = msg->pose.pose.position.y;

    // quaternion to RPY conversion
    tf::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    // angular position
    current_pose.theta = yaw;
    pub_pose2d.publish(current_pose);
}

int main(int argc, char **argv)
{
    const double PI = 3.14159265358979323846;

    ROS_INFO("start");

    ros::init(argc, argv, "move_pub");
    ros::NodeHandle n;
    ros::Subscriber sub_odometry = n.subscribe("odom", 1, odomCallback);
    ros::Publisher movement_pub = n.advertise("cmd_vel",1); //for sensors the value after , should be higher to get a more accurate result (queued)
    pub_pose2d = n.advertise("turtlebot_pose2d", 1);
    ros::Rate rate(10); //the larger the value, the "smoother" , try value of 1 to see "jerk" movement

    //move forward
    ROS_INFO("move forward");
    ros::Time start = ros::Time::now();
    while(ros::ok() && current_pose.x < 1.5)
    {
        geometry_msgs::Twist move;
        //velocity controls
        move.linear.x = 0.2; //speed value m/s
        move.angular.z = 0;
        movement_pub.publish(move);

        ros::spinOnce();
        rate.sleep();
    }
    //turn right
    ROS_INFO("turn right");
    ros::Time start_turn = ros::Time::now();
    while(ros::ok() && current_pose.theta > -PI/2)
    {
        geometry_msgs::Twist move;
        //velocity controls
        move.linear.x = 0; //speed value m/s
        move.angular.z = -0.3;
        movement_pub.publish(move);

        ros::spinOnce();
        rate.sleep();
    }
    //move forward again
    ROS_INFO("move forward");
    ros::Time start2 = ros::Time::now();
    while(ros::ok() && current_pose.y > -1.5)
    {
        geometry_msgs::Twist move;
        //velocity controls
        move.linear.x = 0.2; //speed value m/s
        move.angular.z = 0;
        movement_pub.publish(move);

        ros::spinOnce();
        rate.sleep();
    }

    // just stop
    while(ros::ok()) {
        geometry_msgs::Twist move;
        move.linear.x = 0;
        move.angular.z = 0;
        movement_pub.publish(move);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

*/
