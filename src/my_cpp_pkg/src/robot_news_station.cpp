#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotNewsStationNode : public rclcpp::Node 
{
    private:
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher;
        rclcpp::TimerBase::SharedPtr timer;
        std::string robot_name;

        void callbackSubscribed() 
        {
            auto msg = example_interfaces::msg::String();
            msg.data = std::string("Hi, this is ") + this->robot_name + std::string(" from the robot news station");
            this->publisher->publish(msg);
        }

    public:
        RobotNewsStationNode() : Node("robot_news_station")
        {
            // Declare runtime parameters with default value
            this->declare_parameter("robot_name", "R2D2");

            // Get Runtime Parameters
            this->robot_name = this->get_parameter("robot_name").as_string();

            this->publisher = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
            this->timer = this->create_wall_timer(
                                    std::chrono::milliseconds(500),
                                    std::bind(&RobotNewsStationNode::callbackSubscribed, this)
                                );

            RCLCPP_INFO(this->get_logger(), "Robot news station is broadcasting...");
        }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<RobotNewsStationNode>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}