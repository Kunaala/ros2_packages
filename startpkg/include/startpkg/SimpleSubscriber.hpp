
#include<functional>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include<string>


class SimpleSubscriber : public rclcpp::Node
{
    public:
        SimpleSubscriber();

    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub1_;
        void topic_callback(const std_msgs::msg::String::SharedPtr m1);
};
