#include "SimplePublisher.hpp"
namespace composition
{
    SimplePublisher::SimplePublisher(const rclcpp::NodeOptions &option) : Node("simple_publisher", option)
    {
        SimplePublisher::pub1_ = create_publisher<std_msgs::msg::String>("topic", 10);
        SimplePublisher::timer1_ = create_wall_timer(500ms, std::bind(&SimplePublisher::timer_callback, this));
    }

    void SimplePublisher::timer_callback()
    {
        std_msgs::msg::String m1;
        m1.data = "Welcome to ROS2";
        RCLCPP_INFO(get_logger(), "Publishing %s", m1.data.c_str());
        pub1_->publish(m1);
    }
} // namespace composition
#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(composition::SimplePublisher)