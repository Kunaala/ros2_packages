#include "SimplePublisher.hpp"
#include "SimpleSubscriber.hpp"
int main(int argc, char *argv[])
{

    rclcpp::init(argc, argv);       
    rclcpp::spin(std::make_shared<SimplePublisher>());
    // rclcpp::spin(std::make_shared<SimpleSubscriber>());
    rclcpp::shutdown();
    return 0;
}
