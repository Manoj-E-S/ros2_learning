#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<rclcpp::Node>("add_two_ints_client_no_oop");
    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    // Wait for server to be up and running
    while(!client->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_WARN(node->get_logger(), "Waiting for add_two_ints server to start...");
    }

    // Create a request
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    // auto request = example_interfaces::srv::AddTwoInts::Request::SharedPtr(); -> DOES NOT WORK! Gives segmentation fault!!
    request->a = 20;
    request->b = 10;

    auto future = client->async_send_request(request);
    if (future.valid()) {
        if (rclcpp::spin_until_future_complete(node, future) == rclcpp::FutureReturnCode::SUCCESS) {
            auto sum = future.get()->sum;
            RCLCPP_INFO(node->get_logger(), "%ld + %ld = %ld", request->a, request->b, sum);
        } else {
            RCLCPP_ERROR(node->get_logger(), "Service request for add_two_ints server FAILED!");
        }
    } else {
        RCLCPP_ERROR(node->get_logger(), "Failed to send request to add_two_ints server!");
    }

    rclcpp::shutdown();
    return 0;
}