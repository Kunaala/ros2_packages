
#include <functional>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <string>

namespace composition
{
    class SimpleSubscriber : public rclcpp::Node
    {
    public:
        SimpleSubscriber(const rclcpp::NodeOptions &options);

    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub1_;
        void topic_callback(const std_msgs::msg::String::SharedPtr m1);
    };
} // namespace composition