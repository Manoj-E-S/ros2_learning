#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__('py_test')
        self.__counter = 0

        self.get_logger().info('Hello ROS2!')
        self.create_timer(0.5, self.timer_callback)

    def timer_callback(self):
        self.__counter += 1
        self.get_logger().info(f'Hello: {self.__counter}')

def main(args=None):
    rclpy.init(args=args)

    node = MyNode()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()