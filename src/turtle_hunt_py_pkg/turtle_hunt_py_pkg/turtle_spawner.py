#!/usr/bin/env python3

# python imports
from functools import partial
from random import random, randint
from math import radians, sqrt

# rclpy(ros2) imports
import rclpy
from rclpy.node import Node


# TurtleSpawnerNode imports
from turtlesim.srv import Spawn
from turtlesim.msg import Pose
from my_robot_interfaces.msg import Turtle, TurtleArray

class TurtleSpawnerNode(Node):

    screen_x = 9.0
    screen_y = 9.0

    def __init__(self):
        super().__init__("turtle_spawner")

        self.declare_parameter("spawn_frequency", 1.0)
        self.declare_parameter("turtle_name_prefix", "random_turtle")
        spawn_frequency_ = self.get_parameter("spawn_frequency").value
        self.__turtle_name_prefix = self.get_parameter("turtle_name_prefix").value

        self.__spawn_timer_ = self.create_timer(
            (1.0/spawn_frequency_),
            self.__callback_spawn_timer
        )

        self.__turtle_positions_publisher = self.create_publisher(TurtleArray, "turtle_positions", 10)
        self.__killed_turtles_subscriber = self.create_subscription(Turtle, "killed_turtle", self.__callback_killed_turtle, 10)

        self.__turtles = []
        self.__spawn_counter = 0



    def __callback_spawn_timer(self):
        request = Spawn.Request()

        self.__spawn_counter += 1
        request.name = self.__turtle_name_prefix + str(self.__spawn_counter)
        request.x = random()*TurtleSpawnerNode.screen_x + 0.7
        request.y = random()*TurtleSpawnerNode.screen_y + 0.7
        request.theta = radians(randint(-180, 180))

        self.__callservice_spawn(request)


    def __callservice_spawn(self, request: Spawn.Request) -> None:

        client = self.create_client(Spawn, 'spawn')
        
        # Wait for server to be up and running
        while not client.wait_for_service(1.0):
            self._logger.warn('Waiting for service : spawn')

        future = client.call_async(request)
        future.add_done_callback(partial(self.__callservice_spawn_futureCallback, req=request))


    def __callservice_spawn_futureCallback(self, future, req) -> None:

        try:
            res = future.result()

            if res.name != "":
                turtle = Turtle()
                turtle.name = res.name
                turtle.x = req.x
                turtle.y = req.y
                turtle.theta = req.theta

                self.__turtles.append(turtle)
                self._logger.info(f'{res.name} spawned at ({req.x}, {req.y}), [orientation:{req.theta}]\n')
                self.__publish_turtles()
            else:
                self._logger.warn(f'WARNING : {res.name} not spawned\n')

        except Exception as e:
            self._logger.error(f'Service "/spawn" failed for request {req}\n')

    
    def __publish_turtles(self):
        turtle_array = TurtleArray()
        turtle_array.turtles = self.__turtles
        self.__turtle_positions_publisher.publish(turtle_array)

    def __callback_killed_turtle(self, msg: Turtle):
        for i, turtle in enumerate(self.__turtles):
            if turtle == msg:
                del self.__turtles[i]
                self.__publish_turtles()
                break


def main(args=None):
    rclpy.init(args=args)
    node = TurtleSpawnerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()