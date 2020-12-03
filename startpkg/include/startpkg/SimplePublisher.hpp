#include<chrono>
#include<functional>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include<string>
using namespace std::chrono_literals;
class SimplePublisher : public rclcpp::Node
{
    public:
        SimplePublisher();

    private:
        rclcpp::TimerBase::SharedPtr timer1_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub1_;
        void timer_callback();
};