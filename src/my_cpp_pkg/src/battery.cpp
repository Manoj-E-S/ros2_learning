#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/srv/turn_on_led.hpp"
 
class BatteryNode : public rclcpp::Node
{
    public:
        BatteryNode() : Node("battery"), counter_(0)
        {
            this->timer_ = this->create_wall_timer(
                std::chrono::seconds(1),
                std::bind(&BatteryNode::callback_timer, this)
            );

            RCLCPP_INFO(this->get_logger(), "Battery Draining...");
        }

        void
        callback_timer()
        {
            std::shared_ptr<my_robot_interfaces::srv::TurnOnLed_Request> request;

            // After battery is fully drained
            if ((this->counter_ - BatteryNode::drain_time) % (BatteryNode::drain_time + BatteryNode::recharge_time) == 0)
            {
                request = createRequest_set_led(true);
                threads_.push_back(
                    std::thread(std::bind(&BatteryNode::callService_set_led, this, request))
                );
            }
            // After battery is fully recharged
            else if ((this->counter_) % (BatteryNode::drain_time + BatteryNode::recharge_time) == 0)
            {
                request = createRequest_set_led(false);
                threads_.push_back(
                    std::thread(std::bind(&BatteryNode::callService_set_led, this, request))
                );
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "[Time: %d]", this->counter_);
            }
            (this->counter_)++;
        }

        std::shared_ptr<my_robot_interfaces::srv::TurnOnLed::Request>
        createRequest_set_led(bool state = false) 
        {
            auto request = std::make_shared<my_robot_interfaces::srv::TurnOnLed::Request>();
            request->led_index = BatteryNode::battery_led_index;
            request->state = state;

            return request;
        }

        void
        callService_set_led(my_robot_interfaces::srv::TurnOnLed::Request::SharedPtr req)
        {
            auto client = this->create_client<my_robot_interfaces::srv::TurnOnLed>("set_led");

            while(!client->wait_for_service(std::chrono::seconds(1)))
            {
                RCLCPP_WARN(this->get_logger(), "Waiting for LED Panel to be initialized...");
            }

            auto future = client->async_send_request(req);

            try
            {
                auto res = future.get();
                if(res->success) {
                    RCLCPP_INFO(this->get_logger(), "[Time: %d] Battery Charging... LED[%lu] Turned ON", this->counter_, BatteryNode::battery_led_index);
                }
                else {
                    RCLCPP_INFO(this->get_logger(), "[Time: %d] Battery Charged... LED[%lu] Turned OFF", this->counter_, BatteryNode::battery_led_index);
                }
            } 
            catch(const std::exception& e) 
            {
                RCLCPP_ERROR(this->get_logger(), "Service request for set_led server FAILED!");
            }

        }
    
    private:
        std::vector<std::thread> threads_;
        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;

        const static uint64_t battery_led_index = 1;
        const static int drain_time = 4;
        const static int recharge_time = 6;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BatteryNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}