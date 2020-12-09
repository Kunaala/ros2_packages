#include "ParameterServer.hpp"
namespace composition
{
  ParameterServer::ParameterServer(const rclcpp::NodeOptions &option) : Node("simple_server", option)
  {
    std::function<void(const std::shared_ptr<new_interfaces::srv::CountIncrement::Request>,
                       std::shared_ptr<new_interfaces::srv::CountIncrement::Response>)>
        fcn2 = std::bind(&ParameterServer::inccounter, this, std::placeholders::_1, std::placeholders::_2);
    ParameterServer::serv1 = create_service<new_interfaces::srv::CountIncrement>("count_increment", fcn2);
  }

  void ParameterServer::inccounter(const std::shared_ptr<new_interfaces::srv::CountIncrement::Request> req,
                                   std::shared_ptr<new_interfaces::srv::CountIncrement::Response> res)
  {
    res->result = req->parameter + 5;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\n: %ld"
                                              " response: %ld",
                req->parameter, res->result);
    RCLCPP_INFO(get_logger(), "Incoming request\n: %ld"
                              " response: %ld",
                req->parameter, res->result);
  }

} // namespace composition
#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(composition::ParameterServer)
//ros2 service call /count_increment new_interfaces/srv/CountIncrement "{parameter: 2}"