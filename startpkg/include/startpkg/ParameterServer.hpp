#include "rclcpp/rclcpp.hpp"
#include "new_interfaces/srv/count_increment.hpp"
#include<memory>
class ParameterServer : public rclcpp::Node
{
    public:
        ParameterServer();
        void inccounter(const std::shared_ptr<new_interfaces::srv::CountIncrement::Request> req,
                    std::shared_ptr<new_interfaces::srv::CountIncrement::Response> res);
    private:
        rclcpp::Service<new_interfaces::srv::CountIncrement>::SharedPtr serv1;

}; 
