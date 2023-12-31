#!/usr/bin/env python3

# Import ROS2 libraries
import rclpy
from rclpy.node import Node

# Import messages
from example_interfaces.msg import String

class RobotNewsStationNode(Node):

    def __init__(self):
        super().__init__('robot_news_station')

        self.__robot_name = "C3P0"
        self.__publisher = self.create_publisher(String, 'robot_news', 10)
        self.__logger = self.get_logger()
        self.__timer = self.create_timer(0.5, self.publish_news)

        self.__logger.info("Robot News Station has been started")

    
    def publish_news(self):
        msg = String()
        msg.data = f"Hi, this is {self.__robot_name}, from the robot news station"

        # publish the msg
        self.__publisher.publish(msg)

        # log the msg on the console
        # self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()