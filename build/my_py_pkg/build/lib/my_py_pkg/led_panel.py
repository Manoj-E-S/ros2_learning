#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from my_robot_interfaces.msg import LedArrayStates
from my_robot_interfaces.srv import TurnOnLed

class LedPanelNode(Node):

    def __init__(self):
        super().__init__("led_panel")

        self.led_panel = [False, False, False]
        self.led_panel_publisher_ = self.create_publisher(LedArrayStates, "led_panel_state", 10)
        self.set_led_server_ = self.create_service(TurnOnLed, "set_led", self.serviceCallback_set_led)
        
        self._logger.info(f"LED Panel Initialized: LEDs' State - {self.led_panel}")


    def serviceCallback_set_led(self, request, response):
        # Service Action
        self.led_panel[request.led_index] = request.state
        response.success = True if request.state else False

        # Publish current led_panel state
        msg = LedArrayStates()
        msg.led_states = self.led_panel
        self.led_panel_publisher_.publish(msg)

        self._logger.info(f"LED Panel State - {self.led_panel}")

        return response


def main(args=None):
    rclpy.init(args=args)
    node = LedPanelNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()