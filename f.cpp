#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TransformStamped.h>
#include <stdio.h>
#include <stdlib.h>
#include <sensor_msgs/LaserScan.h>

void scan_callback(const sensor_msgs::LaserScan::ConstPtr &scan_msg)

{

}

void Avoid_distance_A (){
  ros::NodeHandle nh;
  using namespace std;
  ros::Publisher cmd_vel_pub_;
  cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1);

  ros::Subscriber laser_scan = nh.subscribe("/scan", 1000, scan_callback);

  geometry_msgs::Twist base_cmd;
  ros::Rate rate(50); // 50Hz

  float Velocity[]={0, -1.57/2, 1.57/2, 0, 1.57/2, -1.57/2, 0};
  int Loops[]={150, 75, 80, 35, 75, 75, 100};
  double n;

  base_cmd.linear.x = 0.5;
  base_cmd.linear.y = 0;
  base_cmd.linear.z = 0;

  while (nh.ok()){
    for (int i=0; i<7; i++){
      base_cmd.angular.z = Velocity[i];
      n = Loops[i];
      cout<< "The angular velocity is " << Velocity[i] << " and the number of clicks is " << Loops[i] <<endl;
      for (n>0; n--;){
        cmd_vel_pub_.publish(base_cmd);
        rate.sleep();
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
  ros::init(argc, argv, "distance_A");

  Avoid_distance_A();

  return 0;
}
