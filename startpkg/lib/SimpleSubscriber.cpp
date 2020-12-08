
#include "SimpleSubscriber.hpp"

SimpleSubscriber::SimpleSubscriber()
: Node("subscriber_node")
{
    sub1_ = create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&SimpleSubscriber::topic_callback, this, std::placeholders::_1));
}

void SimpleSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr m1)
{
    RCLCPP_INFO(get_logger(), "I heard: '%s'", m1->data.c_str());

}