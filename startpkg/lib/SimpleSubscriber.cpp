
#include "SimpleSubscriber.hpp"
using std::placeholders::_1;

SimpleSubscriber::SimpleSubscriber()
: Node("subscriber_node")
{
    sub1_ = create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&SimpleSubscriber::topic_callback, this, _1));
}

void SimpleSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "I heard: '%s'", msg->data.c_str());

}