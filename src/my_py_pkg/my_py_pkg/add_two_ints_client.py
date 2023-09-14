#!/usr/bin/env python3

# python imports
from functools import partial

# rclpy(ros2) imports
import rclpy
from rclpy.node import Node

# AddTwoIntsClientNode Imports
from example_interfaces.srv import AddTwoInts
 
class AddTwoIntsClientNode(Node):

    def __init__(self):
        super().__init__("add_two_ints_client")

        # Create request and call service
        request = AddTwoInts.Request()
        request.a = 36
        request.b = 33
        self.__callservice_add_two_ints(request)


    def __callservice_add_two_ints(self, request: AddTwoInts.Request) -> None:

        client = self.create_client(AddTwoInts, 'add_two_ints')
        
        # Wait for server to be up and running
        while not client.wait_for_service(1.0):
            self._logger.warn('Waiting for service : add_two_ints')

        future = client.call_async(request)

        # Add a callback for after the asyncronous action is complete
        # This is done as a node that is already alive using rclpy.spin(node) cannot be spun again after future is complete
        # ie. rclpy.spin_until_future_complete(node, future) is INVALID here
        #
        # Note:
        # The below 2 lines are equivalent
        # future.add_done_callback(lambda future_ : self.__callservice_add_two_ints_futureCallback(future_, request))
        future.add_done_callback(partial(self.__callservice_add_two_ints_futureCallback, req=request))


    def __callservice_add_two_ints_futureCallback(self, future, req) -> None:

        # Check if the service was successful
        try:
            res = future.result()
            self._logger.info(f'{req.a} + {req.b} = {res.sum}')
        except Exception as e:
            self._logger.error(f'Service "add_two_ints" failed for request AddTwoInts.Request({req})')
        
 
 
def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClientNode()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()