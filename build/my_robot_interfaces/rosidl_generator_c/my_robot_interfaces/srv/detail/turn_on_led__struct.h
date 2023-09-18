// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:srv/TurnOnLed.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__TURN_ON_LED__STRUCT_H_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__TURN_ON_LED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TurnOnLed in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__TurnOnLed_Request
{
  uint64_t led_index;
  bool state;
} my_robot_interfaces__srv__TurnOnLed_Request;

// Struct for a sequence of my_robot_interfaces__srv__TurnOnLed_Request.
typedef struct my_robot_interfaces__srv__TurnOnLed_Request__Sequence
{
  my_robot_interfaces__srv__TurnOnLed_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__TurnOnLed_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TurnOnLed in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__TurnOnLed_Response
{
  bool success;
} my_robot_interfaces__srv__TurnOnLed_Response;

// Struct for a sequence of my_robot_interfaces__srv__TurnOnLed_Response.
typedef struct my_robot_interfaces__srv__TurnOnLed_Response__Sequence
{
  my_robot_interfaces__srv__TurnOnLed_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__TurnOnLed_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__TURN_ON_LED__STRUCT_H_
