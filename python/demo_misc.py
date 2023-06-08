from functools import wraps
import inspect
from pprint import pprint
import ast
import argparse

class Planet:
    num = 98
    
    def __init__(self, *args, **kwargs):
        self.count = args[0]

    # Decorator as an instance method
    def decorator1(self, func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            print('Decorator 1')
            return func(*args, **kwargs)
        return wrapper

    # Decorator as a class method
    @classmethod
    def decorator2(cls, func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            print('Decorator 2')
            return func(*args, **kwargs)
        return wrapper
    
    @classmethod
    def run(cls):
        walking = 'True'
        return cls

class Transp:
# As an instance method
    planet = Planet(100)

    @planet.decorator1
    def spam(self):
        print('spam')
    
    # As a class method
    @Planet.decorator2
    def grok(self, *args):
        print('grok', args[0])
        pass


class Misc():
    @staticmethod
    def print_values(*args, **kwargs):
        pprint(kwargs.keys())
        pprint(kwargs.values())
        pprint(kwargs.items())

        for x in args:
            pprint(x, indent=1)
        
        for key, value in kwargs.items():
            pprint('{} -> {}'.format(key, value))


# 0. using defined args and kwargs as input
# def main(*args, **kwargs):
#     pprint(kwargs.keys())
#     pprint(kwargs.values())
#     pprint(kwargs.items())
#     for x in args:
#         pprint(x)
    
#     for key, value in kwargs.items():
#         pprint('{} -> {}'.format(key, value))


# 0.1 using argparse
def main(args):
    print(args.user1)
    print(args.user2)
    print(args.pw)

if __name__ == "__main__":
    # 0. using defined args and kwargs as input
    # args = {1, 2, 3}
    # kwargs = {'kwargs_1': 'val_1', 'kwargs_2': 'val_2', 'kwargs_3': 'val_3'}
    # main(*args, **kwargs)   # * operator tells print_values to unpack the list first
    
    # 0.1 using argparser: 
    # python3 test.py --user1 'morning_star' --user2 'mighty' --pw 101
    parser = argparse.ArgumentParser(description='manual to this script')
    parser.add_argument("--user1", type=str, default="0", help='input user name')
    parser.add_argument("--user2", type=str, default="0", help='input user name')
    parser.add_argument("--pw", type=int, default=32,help='input password')
    args = parser.parse_args()
    print(args.user1)
    print(args.user2)
    print(args.pw)
    main(args)


    # 1. list all functions in a module 
    # functions = inspect.getmembers(pprint)
    # pprint(functions)

    # 2. list built-in functions for python
    # pprint(__builtins__)

    # 3. list module attributes
    # y = Planet('11')
    # pprint(y.num)
    # res = y.run()
    # pprint(dir(res))

    # pprint(type(res))
    # pprint(vars(res), indent = 4)
    # pprint(res.__dict__, indent = 4)
    # pprint(dir(y.run))

