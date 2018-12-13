#include "ros/ros.h"
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Float64MultiArray.h>
#include <math.h>
#include <iostream>
#include <string>
#include <iterator>

// Action
#include <algorithm>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/simple_client_goal_state.h>
#include <move_base_msgs/MoveBaseAction.h>

//Markers
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

// Transform System
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>

using namespace std;
using namespace visualization_msgs;
using namespace ros;

class Route
{
private:
  Publisher marker_pub;
  Subscriber cleaning;
  actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> client;

  int counter = 0;

  float points1[10][2] = {

      {-2.71165282756, 4.25877838397},  //C2-6
      {-0.101063539955, 3.08155262643}, //C2-5
      {1.95858022445, 0.991128656044},  //C2-4
      {4.53383390006, 0.896117169989},  //C2-3
      {8.23839786601, -0.775337703146}, //Bathroom
      {10.7671759825, -0.835269893842}, //Front Door
      {8.67784887569, 0.325937184536},  //C2-20
      {5.94365171275, 1.71623561337},   //C2-19
      {3.04355479921, 3.04958077815},   //C2-18
      {-0.890969239754, 6.69025819804}  //C2-17ab
  };

  void _send_goal(int PointoGo)
  {
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.pose.position.x = points1[PointoGo][0];
    goal.target_pose.pose.position.y = points1[PointoGo][1];
    goal.target_pose.pose.position.z = 0;
    goal.target_pose.pose.orientation.w = 1.0;
    while( client.isServerConnected() != true)
    {
      ROS_INFO("Server Is: %s", client.isServerConnected() );
      Duration(1).sleep();
    }
    ROS_INFO("Count: %d X: %f Y: %f", PointoGo, points1[PointoGo][0], points1[PointoGo][1]);
    client.sendGoal(goal, boost::bind(&Route::_target_reached_cb, this, _1, _2));

  }

  void _target_reached_cb(const actionlib::SimpleClientGoalState &state, const move_base_msgs::MoveBaseResultConstPtr &result)
  {
    ROS_INFO("Counter");
    if (counter >= 10)
    {
      counter = 0;
    }
    _send_goal(counter);
    counter++;
  }

  void points(const geometry_msgs::PointStamped::ConstPtr &msg)
  {
    vector<float> tmp;
    tmp.push_back(msg->point.x); //makes the vector
    tmp.push_back(msg->point.y);
    //_send_goal (tmp);
  }

public:
  Route() : client("move_base")
  {
    ros::NodeHandle n;
    //marker_pub = n.advertise<visualization_msgs::MarkerArray>("busroute_markers", 1);
    //cleaning = n.subscribe("clicked_point", 1, &Route::points, this);
    _send_goal(counter);
  }
  ~Route(){}
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "driver");

  Route r;


  while (ros::ok())
  {
    ros::spinOnce();
  }

  return 0;
}
