#!/usr/bin/env python3

# python imports
from math import sqrt, atan2, pi
from functools import partial

from sympy import N

# rclpy(ros2) imports
import rclpy
from rclpy.node import Node


# Turtle1ControllerNode imports
from turtlesim.msg import Pose
from turtlesim.srv import Kill
from geometry_msgs.msg import Twist
from my_robot_interfaces.msg import TurtleArray, Turtle

class Turtle1ControllerNode(Node):
    def __init__(self):
        super().__init__("turtle1_controller")

        # Runtime params and flags
        self.declare_parameter("catch_closest_turtle", True)
        self.__catch_closest_turtle_flag = self.get_parameter("catch_closest_turtle").value

        self.__pose_subscriber = self.create_subscription(
            Pose, 
            '/turtle1/pose', 
            self.__callback_pose_subscription,
            10
        )

        self.__turtle_positions_subscriber = self.create_subscription(
            TurtleArray, 
            "turtle_positions", 
            self.__callback_turtle_positions_subscription,
            10
        )

        self.__control_loop_timer = self.create_timer(
            0.1,
            self.__control_loop
        )

        self.__pose = None
        self.__turtle_to_catch = None
        self.__cmd_vel_publisher = self.create_publisher(Twist, "/turtle1/cmd_vel", 10)
        self.__killed_turtle_publisher = self.create_publisher(Turtle, "killed_turtle", 10)
        self.__catchable_turtles = []

    
    def __control_loop(self):
        if self.__pose is None or self.__turtle_to_catch is None:
            return

        x = self.__turtle_to_catch.x - self.__pose.x
        y = self.__turtle_to_catch.y - self.__pose.y
        distance_to_target = sqrt((x)**2 + (y)**2)
        angle_to_target = atan2(y, x)
        diff_angle = angle_to_target - self.__pose.theta

        if diff_angle < -pi:
            diff_angle += 2*pi
        elif diff_angle > pi:
            diff_angle -= 2*pi

        twist = Twist()
        if distance_to_target < 0.3:
            twist.linear.x = 0.0
            twist.angular.z = 0.0
            self.__cmd_vel_publisher.publish(twist)
            self.__callservice_kill(self.__turtle_to_catch.name)
            return
        
        twist.linear.x = 2.0 * distance_to_target
        twist.angular.z = 6.0 * diff_angle
        self.__cmd_vel_publisher.publish(twist)


    def __callback_pose_subscription(self, msg):
        self.__pose = msg


    def __callback_turtle_positions_subscription(self, msg: TurtleArray):

        self.__catchable_turtles = msg.turtles

        if len(self.__catchable_turtles) > 0:
            if not self.__catch_closest_turtle_flag:
                self.__turtle_to_catch = self.__catchable_turtles[0]
                return
            
            closest_turtle = None
            closest_distance = None
            for turtle in self.__catchable_turtles:
                curr_distance = sqrt((turtle.x - self.__pose.x)**2 + (turtle.y - self.__pose.y)**2)
                if closest_turtle is None or curr_distance < closest_distance:
                    closest_turtle = turtle
                    closest_distance = curr_distance

            self.__turtle_to_catch = closest_turtle
            return
        
        self.__turtle_to_catch = None


    def __callservice_kill(self, turtle_name) -> None:

        client = self.create_client(Kill, 'kill')
        
        # Wait for server to be up and running
        while not client.wait_for_service(1.0):
            self._logger.warn('Waiting for service : kill')

        request = Kill.Request()
        request.name = turtle_name

        future = client.call_async(request)
        future.add_done_callback(partial(self.__callservice_kill_futureCallback, turtle_name=request.name))



    def __callservice_kill_futureCallback(self, future, turtle_name) -> None:

        try:
            res = future.result()
            self.__turtle_to_catch = None

            self._logger.info(f'{turtle_name} is killed')
            
            for i, turtle in enumerate(self.__catchable_turtles):
                if turtle.name == turtle_name:
                    self.__killed_turtle_publisher.publish(turtle)
                    break
        except Exception as e:
            self._logger.error(f'ERROR : {e}\n')


def main(args=None):
    rclpy.init(args=args)
    node = Turtle1ControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()