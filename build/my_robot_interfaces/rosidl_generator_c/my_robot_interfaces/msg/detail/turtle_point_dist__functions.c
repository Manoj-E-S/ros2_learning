// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/TurtlePointDist.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/turtle_point_dist__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `turtle_name`
#include "rosidl_runtime_c/string_functions.h"

bool
my_robot_interfaces__msg__TurtlePointDist__init(my_robot_interfaces__msg__TurtlePointDist * msg)
{
  if (!msg) {
    return false;
  }
  // turtle_name
  if (!rosidl_runtime_c__String__init(&msg->turtle_name)) {
    my_robot_interfaces__msg__TurtlePointDist__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->turtle_name, "");
    if (!success) {
      goto abort_init_0;
    }
  }
  // x
  msg->x = -1.0l;
  // y
  msg->y = -1.0l;
  // distance
  msg->distance = -1.0l;
  return true;
abort_init_0:
  return false;
}

void
my_robot_interfaces__msg__TurtlePointDist__fini(my_robot_interfaces__msg__TurtlePointDist * msg)
{
  if (!msg) {
    return;
  }
  // turtle_name
  rosidl_runtime_c__String__fini(&msg->turtle_name);
  // x
  // y
  // distance
}

bool
my_robot_interfaces__msg__TurtlePointDist__are_equal(const my_robot_interfaces__msg__TurtlePointDist * lhs, const my_robot_interfaces__msg__TurtlePointDist * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // turtle_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->turtle_name), &(rhs->turtle_name)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__TurtlePointDist__copy(
  const my_robot_interfaces__msg__TurtlePointDist * input,
  my_robot_interfaces__msg__TurtlePointDist * output)
{
  if (!input || !output) {
    return false;
  }
  // turtle_name
  if (!rosidl_runtime_c__String__copy(
      &(input->turtle_name), &(output->turtle_name)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // distance
  output->distance = input->distance;
  return true;
}

my_robot_interfaces__msg__TurtlePointDist *
my_robot_interfaces__msg__TurtlePointDist__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__TurtlePointDist * msg = (my_robot_interfaces__msg__TurtlePointDist *)allocator.allocate(sizeof(my_robot_interfaces__msg__TurtlePointDist), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__TurtlePointDist));
  bool success = my_robot_interfaces__msg__TurtlePointDist__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__TurtlePointDist__destroy(my_robot_interfaces__msg__TurtlePointDist * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__TurtlePointDist__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__TurtlePointDist__Sequence__init(my_robot_interfaces__msg__TurtlePointDist__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__TurtlePointDist * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__TurtlePointDist *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__TurtlePointDist), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__TurtlePointDist__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__TurtlePointDist__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_robot_interfaces__msg__TurtlePointDist__Sequence__fini(my_robot_interfaces__msg__TurtlePointDist__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__TurtlePointDist__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_robot_interfaces__msg__TurtlePointDist__Sequence *
my_robot_interfaces__msg__TurtlePointDist__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__TurtlePointDist__Sequence * array = (my_robot_interfaces__msg__TurtlePointDist__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__TurtlePointDist__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__TurtlePointDist__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__TurtlePointDist__Sequence__destroy(my_robot_interfaces__msg__TurtlePointDist__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__TurtlePointDist__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__TurtlePointDist__Sequence__are_equal(const my_robot_interfaces__msg__TurtlePointDist__Sequence * lhs, const my_robot_interfaces__msg__TurtlePointDist__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__TurtlePointDist__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__TurtlePointDist__Sequence__copy(
  const my_robot_interfaces__msg__TurtlePointDist__Sequence * input,
  my_robot_interfaces__msg__TurtlePointDist__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__TurtlePointDist);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__TurtlePointDist * data =
      (my_robot_interfaces__msg__TurtlePointDist *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__TurtlePointDist__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__TurtlePointDist__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__TurtlePointDist__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
