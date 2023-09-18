
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    # Remap tuples: (topic, srv, etc.) [--ros-args -r]
    remapTopic_number = ("number", "my_number")
    remapTopic_number_count = ("number_count", "my_number_count")

    # Runtime Parameter dictionaries: [--ros-args -p]
    param_number_to_publish = {"number_to_publish": 225}
    param_publish_frequency = {"publish_frequency": 5.0}

    number_publisher_node = Node(
        package="my_py_pkg",
        executable="number_publisher",
        name="number_publisher_1",
        remappings = [
            remapTopic_number,
        ],
        parameters=[
            param_number_to_publish,
            param_publish_frequency,
        ]
    )

    number_counter_node = Node(
        package="my_cpp_pkg",
        executable="number_counter",
        name="number_counter_1",
        remappings = [
            remapTopic_number,
            remapTopic_number_count,
        ],
        parameters=[
            
        ]
    )

    ld.add_action(number_publisher_node)
    ld.add_action(number_counter_node)
    return ld