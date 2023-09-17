#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class AddTwoIntsServerNode : public rclcpp::Node
{
    public:
        AddTwoIntsServerNode() : Node("number_counter"), counter_(0)
        {
            this->subscriber_ = this->create_subscription<std_msgs::msg::Int64>(
                                    "number", 
                                    10, 
                                    std::bind(&AddTwoIntsServerNode::subscriberCallback_number, this, std::placeholders::_1)
                                );

            this->publisher_ = this->create_publisher<std_msgs::msg::Int64>("number_count", 10);
            this->reset_counter_server_ = this->create_service<example_interfaces::srv::SetBool>(
                                            "reset_number_count", 
                                            std::bind(&AddTwoIntsServerNode::serviceCallback_reset_number_count, this, _1, _2)
                                        );

            RCLCPP_INFO(this->get_logger(), "Number Counter Initialized.");
        }
    
    private:
        rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
        rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscriber_;
        rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr reset_counter_server_;
        int counter_;

        void serviceCallback_reset_number_count(
            example_interfaces::srv::SetBool::Request::SharedPtr request,
            example_interfaces::srv::SetBool::Response::SharedPtr response
        )
        {
            if(request->data == true)
            {
                this->counter_ = 0;
                response->success = true;
                response->message = "Counter-reset successful";
                return;
            }
            response->success = false;
            response->message = "Counter Not reset";
        }

        void subscriberCallback_number(std_msgs::msg::Int64 msg)
        {
            RCLCPP_INFO(this->get_logger(), "%d", this->counter_);
            this->publishCounter();
            this->counter_ += static_cast<int>(msg.data);
        }

        void publishCounter()
        {
            auto msg = std_msgs::msg::Int64();
            msg.data = this->counter_;
            (this->publisher_)->publish(msg);
        }
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsServerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}