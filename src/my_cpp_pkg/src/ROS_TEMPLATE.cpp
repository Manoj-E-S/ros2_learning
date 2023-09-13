#include "rclcpp/rclcpp.hpp"
 
class NumberCounter : public rclcpp::Node // MODIFY NAME
{
    public:
        NumberCounter() : Node("node_name") // MODIFY NAME
        {
        }
    
    private:
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounter>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}