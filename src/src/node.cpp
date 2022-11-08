#include <ros/ros.h>

#include <geometry_msgs/Twist.h>
#include <autoware_msgs/VehicleCmd.h>
// thread
#include <thread>

// thread function
void threadFunction(const ros::Publisher &pub)
{
    // publish rate
    ros::Rate loop_rate(20);

    // message
    autoware_msgs::VehicleCmd msg;
    msg.twist_cmd.twist.linear.x = 1.0;

    // loop
    while (ros::ok())
    {
        // publish
        pub.publish(msg);

        // sleep
        loop_rate.sleep();
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_vel_slow");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<autoware_msgs::VehicleCmd>("/cmd_vel", 1);
    threadFunction(pub);
    return 0;
}

