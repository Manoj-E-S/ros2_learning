#!/usr/bin/env python3

# rclpy imports
import rclpy
from rclpy.node import Node

# Messages
from std_msgs.msg import Int64

 
class NumberPublisherNode(Node):
    def __init__(self):
        super().__init__("number_publisher")

        # Declare runtime parameters
        # `ros2 run <pkg_name> <exec_name> --ros-args -p <param1_name>:=value1 -p <param2_name>:=value2`
        self.declare_parameter("number_to_publish", 143)
        self.declare_parameter("publish_frequency", 0.5)

        # Get parameter value at runtime
        self.__number = self.get_parameter("number_to_publish").value
        NumberPublisherNode.publish_frequency = self.get_parameter("publish_frequency").value

        self.__logger = self.get_logger()
        self.__publisher = self.create_publisher(Int64, "number", 10)
        self.__timer = self.create_timer(
            (1/NumberPublisherNode.publish_frequency),
            self.publish_number
        )

        self.__logger.info(f'Number Publisher Publishing {self.__number}')

    def publish_number(self):
        msg = Int64()
        msg.data = self.__number
        self.__publisher.publish(msg)
 
 
def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

 
if __name__ == "__main__":
    main()