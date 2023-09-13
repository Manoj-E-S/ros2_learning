#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class SmartphoneNode : public rclcpp::Node
{
    private:
        rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber;

        void callbackSubscribed(const example_interfaces::msg::String poll_msg)
        {
            RCLCPP_INFO(this->get_logger(), "Hearing: '%s'", poll_msg.data.c_str());
        }

    public:
        SmartphoneNode() : Node("smartphone")
        {
            this->subscriber = this->create_subscription<example_interfaces::msg::String>(
                                    "robot_news",
                                    10,
                                    std::bind(&SmartphoneNode::callbackSubscribed, this, std::placeholders::_1)
                                );

            RCLCPP_INFO(this->get_logger(), "Smartphone Listening...");
        }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<SmartphoneNode>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}