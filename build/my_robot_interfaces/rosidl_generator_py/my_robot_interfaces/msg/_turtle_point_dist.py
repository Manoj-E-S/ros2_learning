# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_interfaces:msg/TurtlePointDist.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TurtlePointDist(type):
    """Metaclass of message 'TurtlePointDist'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robot_interfaces.msg.TurtlePointDist')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__turtle_point_dist
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__turtle_point_dist
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__turtle_point_dist
            cls._TYPE_SUPPORT = module.type_support_msg__msg__turtle_point_dist
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__turtle_point_dist

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TURTLE_NAME__DEFAULT': '',
            'X__DEFAULT': -1.0,
            'Y__DEFAULT': -1.0,
            'DISTANCE__DEFAULT': -1.0,
        }

    @property
    def TURTLE_NAME__DEFAULT(cls):
        """Return default value for message field 'turtle_name'."""
        return ''

    @property
    def X__DEFAULT(cls):
        """Return default value for message field 'x'."""
        return -1.0

    @property
    def Y__DEFAULT(cls):
        """Return default value for message field 'y'."""
        return -1.0

    @property
    def DISTANCE__DEFAULT(cls):
        """Return default value for message field 'distance'."""
        return -1.0


class TurtlePointDist(metaclass=Metaclass_TurtlePointDist):
    """Message class 'TurtlePointDist'."""

    __slots__ = [
        '_turtle_name',
        '_x',
        '_y',
        '_distance',
    ]

    _fields_and_field_types = {
        'turtle_name': 'string',
        'x': 'double',
        'y': 'double',
        'distance': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.turtle_name = kwargs.get(
            'turtle_name', TurtlePointDist.TURTLE_NAME__DEFAULT)
        self.x = kwargs.get(
            'x', TurtlePointDist.X__DEFAULT)
        self.y = kwargs.get(
            'y', TurtlePointDist.Y__DEFAULT)
        self.distance = kwargs.get(
            'distance', TurtlePointDist.DISTANCE__DEFAULT)

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.turtle_name != other.turtle_name:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.distance != other.distance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def turtle_name(self):
        """Message field 'turtle_name'."""
        return self._turtle_name

    @turtle_name.setter
    def turtle_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'turtle_name' field must be of type 'str'"
        self._turtle_name = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._distance = value
