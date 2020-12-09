#include "rclcpp/rclcpp.hpp"
#include "new_interfaces/srv/count_increment.hpp"
#include <memory>
namespace composition
{
    class ParameterServer : public rclcpp::Node
    {
    public:
        // COMPOSITION_PUBLIC
        explicit ParameterServer(const rclcpp::NodeOptions &options);
        void inccounter(const std::shared_ptr<new_interfaces::srv::CountIncrement::Request> req,
                        std::shared_ptr<new_interfaces::srv::CountIncrement::Response> res);

    private:
        rclcpp::Service<new_interfaces::srv::CountIncrement>::SharedPtr serv1;
    };
} // namespace composition
