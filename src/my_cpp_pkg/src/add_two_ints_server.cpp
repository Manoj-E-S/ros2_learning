#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class AddTwoIntsServerNode : public rclcpp::Node
{
    public:
        AddTwoIntsServerNode() : Node("add_two_ints_server")
        {
            this->server_ = this->create_service<example_interfaces::srv::AddTwoInts>(
                                "add_two_ints", 
                                std::bind(&AddTwoIntsServerNode::callback_add_two_ints_server, this, _1, _2)
                            );

            RCLCPP_INFO(this->get_logger(), "add_two_ints Server is up and running...");
        }

        void callback_add_two_ints_server(
            example_interfaces::srv::AddTwoInts::Request::SharedPtr request, 
            example_interfaces::srv::AddTwoInts::Response::SharedPtr response
        )
        {
            response->sum = request->a + request->b;
            RCLCPP_INFO(this->get_logger(), "%ld + %ld = %ld", request->a, request->b, response->sum);
        }
    
    private:
        rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsServerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}