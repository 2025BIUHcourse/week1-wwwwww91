#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtle_circle_cpp");
    ros::NodeHandle n;
    
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    
    ros::Rate loop_rate(10);
    
    geometry_msgs::Twist twist;
    
    twist.linear.x = 2.0;   
    twist.angular.z = 1.0;  
    
    ROS_INFO("开始控制小乌龟画圆...");
    
    while(ros::ok())
    {
        turtle_vel_pub.publish(twist);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
    