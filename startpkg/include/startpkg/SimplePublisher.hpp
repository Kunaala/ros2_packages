#include <chrono>
#include <functional>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <string>
using namespace std::chrono_literals;
namespace composition
{
    class SimplePublisher : public rclcpp::Node
    {
    public:
        // COMPOSITION_PUBLIC
        explicit SimplePublisher(const rclcpp::NodeOptions &options);

    private:
        rclcpp::TimerBase::SharedPtr timer1_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub1_;
        void timer_callback();
    };
} // namespace composition