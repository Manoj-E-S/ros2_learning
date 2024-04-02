// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/TurtlePointDist.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POINT_DIST__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POINT_DIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/turtle_point_dist__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtlePointDist_distance
{
public:
  explicit Init_TurtlePointDist_distance(::my_robot_interfaces::msg::TurtlePointDist & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::TurtlePointDist distance(::my_robot_interfaces::msg::TurtlePointDist::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::TurtlePointDist msg_;
};

class Init_TurtlePointDist_y
{
public:
  explicit Init_TurtlePointDist_y(::my_robot_interfaces::msg::TurtlePointDist & msg)
  : msg_(msg)
  {}
  Init_TurtlePointDist_distance y(::my_robot_interfaces::msg::TurtlePointDist::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TurtlePointDist_distance(msg_);
  }

private:
  ::my_robot_interfaces::msg::TurtlePointDist msg_;
};

class Init_TurtlePointDist_x
{
public:
  explicit Init_TurtlePointDist_x(::my_robot_interfaces::msg::TurtlePointDist & msg)
  : msg_(msg)
  {}
  Init_TurtlePointDist_y x(::my_robot_interfaces::msg::TurtlePointDist::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TurtlePointDist_y(msg_);
  }

private:
  ::my_robot_interfaces::msg::TurtlePointDist msg_;
};

class Init_TurtlePointDist_turtle_name
{
public:
  Init_TurtlePointDist_turtle_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtlePointDist_x turtle_name(::my_robot_interfaces::msg::TurtlePointDist::_turtle_name_type arg)
  {
    msg_.turtle_name = std::move(arg);
    return Init_TurtlePointDist_x(msg_);
  }

private:
  ::my_robot_interfaces::msg::TurtlePointDist msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::TurtlePointDist>()
{
  return my_robot_interfaces::msg::builder::Init_TurtlePointDist_turtle_name();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POINT_DIST__BUILDER_HPP_
