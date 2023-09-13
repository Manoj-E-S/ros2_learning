#!/usr/bin/env python3

# Import ROS2 libraries
import rclpy
from rclpy.node import Node

# Import messages
from example_interfaces.msg import String

class RobotNewsSubscriberNode(Node):

    def __init__(self):
        super().__init__('robot_news_subscriber')

        self.__subscriber = self.create_subscription(String, 'robot_news', self.callback_subscribed, 10)
        self.__logger = self.get_logger()

        self.__logger.info("Subscriber Listening to robot_news topic")

    
    def callback_subscribed(self, msg):
        self.__logger.info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsSubscriberNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()