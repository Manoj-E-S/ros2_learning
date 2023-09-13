#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
private:
    // Declare a publisher
    // rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    // Declare a timer
    rclcpp::TimerBase::SharedPtr timer_;

    // Declare a counter
    size_t counter_;

    void timerCallback()
    {
        // Create a message
        // auto message = std_msgs::msg::String();
        // message.data = "Hello, ROS2! " + std::to_string(count_++);

        // Publish the message
        // publisher_->publish(message);
        this->counter_++;
        RCLCPP_INFO(this->get_logger(), "Hello: %ld", this->counter_);
    }

public:
    MyNode() : Node("cpp_test"), counter_(0) {
        RCLCPP_INFO(this->get_logger(), "Hello, ROS2!");
        this->timer_ = this->create_wall_timer(
                                std::chrono::seconds(1),
                                std::bind(&MyNode::timerCallback, this)
                            );
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}