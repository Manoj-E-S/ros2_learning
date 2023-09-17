#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
 
class AddTwoIntsClientNode : public rclcpp::Node
{
    public:
        AddTwoIntsClientNode() : Node("add_two_ints_client")
        {
            auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
            request->a = 12;
            request->b = 18;
            threads_.push_back(
                std::thread(std::bind(&AddTwoIntsClientNode::callService_add_two_ints, this, request))
            );
        }

        void callService_add_two_ints(example_interfaces::srv::AddTwoInts::Request::SharedPtr req)
        {
            auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

            while(!client->wait_for_service(std::chrono::seconds(1)))
            {
                RCLCPP_WARN(this->get_logger(), "Waiting for add_two_ints server to start...");
            }

            auto future = client->async_send_request(req);

            try
            {
                auto res = future.get();
                RCLCPP_INFO(this->get_logger(), "%ld + %ld = %ld", req->a, req->b, res->sum);
            } 
            catch(const std::exception& e) 
            {
                RCLCPP_ERROR(this->get_logger(), "Service request for add_two_ints server FAILED!");
            }

        }
    
    private:
        std::vector<std::thread> threads_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsClientNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}