#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
 
class AddTwoIntsServerNode : public rclcpp::Node
{
    public:
        AddTwoIntsServerNode() : Node("number_counter"), counter_(0)
        {
            this->subscriber_ = this->create_subscription<std_msgs::msg::Int64>(
                                    "number", 
                                    10, 
                                    std::bind(&AddTwoIntsServerNode::callbackSubscribed, this, std::placeholders::_1)
                                );

            this->publisher_ = this->create_publisher<std_msgs::msg::Int64>("number_count", 10);

            RCLCPP_INFO(this->get_logger(), "Number Counter Initialized.");
        }
    
    private:
        rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
        rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscriber_;
        int counter_;

        void callbackSubscribed(std_msgs::msg::Int64 msg)
        {
            this->counter_ += static_cast<int>(msg.data);
            RCLCPP_INFO(this->get_logger(), "%d", this->counter_);
            this->publishCounter();
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