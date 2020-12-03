#include "SimplePublisher.hpp"

SimplePublisher::SimplePublisher(): Node("simple_publisher")
{
    SimplePublisher::pub1_ = create_publisher<std_msgs::msg::String>("topic",10);
    SimplePublisher::timer1_= create_wall_timer(500ms, std::bind(&SimplePublisher::timer_callback,this));
}

void SimplePublisher::timer_callback()
{
    std_msgs::msg::String m1;
    m1.data="Welcome to ROS2";
    RCLCPP_INFO(get_logger(), "Publishing %s", m1.data.c_str());
    pub1_->publish(m1);
}

// #include "rclcpp_components/register_node_macro.hpp"

// RCLCPP_COMPONENTS_REGISTER_NODE(SimplePublisher)