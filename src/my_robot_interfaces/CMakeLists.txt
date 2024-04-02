cmake_minimum_required(VERSION 3.8)
project(my_robot_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
# (Add a find_package(<dependency_name> REQUIRED) for every <build_depend> in package.xml)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# For rosidl to generate the custom interfaces:
rosidl_generate_interfaces(
  ${PROJECT_NAME}
  "msg/LedArrayStates.msg"
  "msg/Turtle.msg"
  "msg/TurtleArray.msg"
  "srv/TurnOnLed.srv"
)

# 
# Removed testing block present here
# 

# export dependencies
# (Add a ament_export_dependencies(<dependency_name>) for every <exec_depend> in package.xml)
ament_export_dependencies(rosidl_default_runtime)

ament_package()
