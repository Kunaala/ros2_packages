
#include "SimpleSubscriber.hpp"
namespace composition
{
    SimpleSubscriber::SimpleSubscriber(const rclcpp::NodeOptions &option)
        : Node("subscriber_node", option)
    {
        sub1_ = create_subscription<std_msgs::msg::String>(
            "topic", 10, std::bind(&SimpleSubscriber::topic_callback, this, std::placeholders::_1));
    }

    void SimpleSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr m1)
    {
        RCLCPP_INFO(get_logger(), "I heard: '%s'", m1->data.c_str());
    }
} // namespace composition
#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(composition::SimpleSubscriber)