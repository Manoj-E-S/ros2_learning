#!/usr/bin/env python3

# rclpy imports
import rclpy
from rclpy.node import Node

# Messages
from std_msgs.msg import Int64

 
class NumberPublisherNode(Node):
    def __init__(self):
        super().__init__("number_publisher")

        self.__number = 143
        self.__logger = self.get_logger()
        self.__publisher = self.create_publisher(Int64, "number", 10)
        self.__timer = self.create_timer(0.5, self.publish_number)      # 2Hz publish rate

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