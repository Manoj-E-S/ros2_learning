
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    # Remap tuples: (topic, srv, etc.) [--ros-args -r]
    remapTopic_robot_news = ("robot_news", "robo_fm")

    # Runtime Parameter dictionaries: [--ros-args -p]
    params = [
        {"robot_name": "giskard"},
        {"robot_name": "bb8"},
        {"robot_name": "daneel"},
        {"robot_name": "c3po"},
        {"robot_name": "vikram"},
    ]
    

    # Create 5 robot_news_station nodes
    for i in range(5):
        robot_news_station_node = Node(
            package="my_cpp_pkg",
            executable="robot_news_station",
            name=f"robot_news_station_{params[i]['robot_name']}",
            remappings=[
                remapTopic_robot_news,
            ],
            parameters=[
                params[i],
            ],
        )

        ld.add_action(robot_news_station_node)


    smartphone_node = Node(
        package="my_py_pkg",
        executable="robot_news_subscriber",
        name="smartphone1",
        remappings=[
            remapTopic_robot_news
        ],
        parameters=[

        ],
    )

    ld.add_action(smartphone_node)


    return ld