// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/TurtlePositionArray.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POSITION_ARRAY__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POSITION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "my_robot_interfaces/msg/detail/turtle_point_dist__struct.h"

/// Struct defined in msg/TurtlePositionArray in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__TurtlePositionArray
{
  my_robot_interfaces__msg__TurtlePointDist__Sequence data;
} my_robot_interfaces__msg__TurtlePositionArray;

// Struct for a sequence of my_robot_interfaces__msg__TurtlePositionArray.
typedef struct my_robot_interfaces__msg__TurtlePositionArray__Sequence
{
  my_robot_interfaces__msg__TurtlePositionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__TurtlePositionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_POSITION_ARRAY__STRUCT_H_
