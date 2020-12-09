#include "SimplePublisher.hpp"
#include "SimpleSubscriber.hpp"
#include "ParameterServer.hpp"
int main(int argc, char *argv[])
{

    rclcpp::init(argc, argv);
    rclcpp::executors::SingleThreadedExecutor exec;
    rclcpp::NodeOptions options;

    auto publish = std::make_shared<composition::SimplePublisher>(options);
    exec.add_node(publish);
    auto server = std::make_shared<composition::ParameterServer>(options);
    exec.add_node(server);
    auto subscribe = std::make_shared<composition::SimpleSubscriber>(options);
    exec.add_node(subscribe);
    exec.spin();
    rclcpp::shutdown();
    return 0;
}