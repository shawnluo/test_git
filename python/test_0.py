# -*- coding: utf-8 -*-
from functools import wraps
import inspect
from pprint import pprint
import ast
import sys
import argparse
import click


# def main(argv):
#     # pprint(kwargs.keys())
#     # pprint(kwargs.values())
#     # pprint(kwargs.items())
#     # for x in args:
#     #     pprint(x)
    
#     # for key, value in kwargs.items():
#     #     pprint('{} -> {}'.format(key, value))

#     parser = argparse.ArgumentParser(description='manual to this script')
#     parser.add_argument('-u', \
#                         '--user1', \
#                         type=str, \
#                         default='0', \
#                         help='input user name')
#     parser.add_argument("--user2", type=str, default="0", help='input user name')
#     parser.add_argument("--pw", type=int, default=32,help='input password')
#     argv = parser.parse_args()
#     # print(args.user1)
#     # print(args.user2)
#     # print(args.pw)

#     print(argv.user1)
#     print(argv.user2)
#     print(argv.pw)


print('ggggggggggggg')

result = 0
@click.command()
@click.option('--num1',
              default = 1,
              help = 'Enter a float value',
              type = float)
@click.option('--num2',
              default = 1,
              prompt = 'Enter a float value',
              help='float type',
              type = float)
@click.option('--op',
              default = '+',
              help = 'Enter the operator')

def calculator(num1=100, num2=200, op='+'):
    if op == '+':
        result = num1 + num2
    if op == '-':
        result = num1 - num2

    click.echo("num1: %f num2: %f op: %s" %num1, %num2, %op)


def main():
    pass

if __name__ == '__main__':
    main()