from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
    )

    turtle1_controller = Node(
        package="turtle_hunt_py_pkg",
        executable="turtle1_controller",
        parameters=[
            {"catch_closest_turtle": True},
        ]
    )

    turtle_spawner = Node(
        package="turtle_hunt_py_pkg",
        executable="turtle_spawner",
        parameters=[
            {"spawn_frequency": 1.0},
            {"turtle_name_prefix": "immobile_turtle"},
        ]
    )


    ld.add_action(turtlesim_node)
    ld.add_action(turtle1_controller)
    ld.add_action(turtle_spawner)

    return ld