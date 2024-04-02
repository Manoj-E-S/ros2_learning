// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/TurtlePointDist.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POINT_DIST__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POINT_DIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__TurtlePointDist __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__TurtlePointDist __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurtlePointDist_
{
  using Type = TurtlePointDist_<ContainerAllocator>;

  explicit TurtlePointDist_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->turtle_name = "";
      this->x = -1.0;
      this->y = -1.0;
      this->distance = -1.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->turtle_name = "";
      this->x = 0.0;
      this->y = 0.0;
      this->distance = 0.0;
    }
  }

  explicit TurtlePointDist_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : turtle_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->turtle_name = "";
      this->x = -1.0;
      this->y = -1.0;
      this->distance = -1.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->turtle_name = "";
      this->x = 0.0;
      this->y = 0.0;
      this->distance = 0.0;
    }
  }

  // field types and members
  using _turtle_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _turtle_name_type turtle_name;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _distance_type =
    double;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__turtle_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->turtle_name = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__TurtlePointDist
    std::shared_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__TurtlePointDist
    std::shared_ptr<my_robot_interfaces::msg::TurtlePointDist_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtlePointDist_ & other) const
  {
    if (this->turtle_name != other.turtle_name) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtlePointDist_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtlePointDist_

// alias to use template instance with default allocator
using TurtlePointDist =
  my_robot_interfaces::msg::TurtlePointDist_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POINT_DIST__STRUCT_HPP_
