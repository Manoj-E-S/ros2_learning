#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts
 
def main(args=None):
    rclpy.init(args=args)
    
    node = Node("add_two_ints_no_oop")
    client = node.create_client(AddTwoInts, "add_two_ints")

    # Wait for server to be up and running
    # Treat the returned boolean of client.wait_for_service(wait_frequency) as a boolean returned by is_server_up(wait_frequency)
    while not client.wait_for_service(1.0):
        node.get_logger().warn("Waiting for service add_two_ints...")
    
    # Create service request
    req = AddTwoInts.Request()
    req.a = 26
    req.b = 43

    # Request service
    # Returned object is of asyncio.Future type
    # The response from server can be extracted using asyncio.Future().result()
    future = client.call_async(req)

    # Keep the node alive until the asyncronous action is complete
    rclpy.spin_until_future_complete(node, future)

    # Check if the service succeeded or failed
    try:
        res = future.result()
        node.get_logger().info(f'{req.a} + {req.b} = {res.sum}')
    except Exception as e:
        node.get_logger().error(f'Service failed: {e:%r}')

    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()