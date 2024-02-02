# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import sys
import pprint
from functools import reduce
import os
import random

from collections import deque

class A:
    def add(self, x):
        y = x + 1
        # print(y)
        
class B(A):
    def add(self, x):
        super().add(x)  # 调用父类中的add函数

b = B()
b.add(4)

#########################

res = os.path.exists('./test') # if folder exist
# print(res)

res = os.path.isfile('./test.py')
# print(res)

#########################

class Employee:
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@company.com'

    def fullname(self):
        print('{} {}'.format(self.first, self.last))
        
emp_1 = Employee('Corey', 'Schafer', 50000)
emp_2 = Employee('Mike', 'Wallace', 60000)

# print(emp_1.email)
# print(emp_2.email)
# print(emp_1.fullname())

SLANG = {'left': 'Hang a Louie.',
         'right': 'Hang a Ralph.',
         'straight': 'Hang a Sam.',
         'u': 'Bang a you-ee.'}

SLANG2 = {'left': 'tesla',
         'right': 'google'};

def drive_sim2(num: int):
    action_count = dict()
    for i in range(num):
        dir = random.random()
        if dir <= 0.05:
            action = 'u'
        elif dir <= 0.2:
            action = 'left'
        elif dir <= 0.4:
            action = 'right'
        else:
            action = 'straight'
        action_count[action] = action_count.get(action, 0) + 1
        print(i + 1, SLANG[action])
    print(action_count)  

def drive_sim(num_intersections: int):
    action_count = dict()
    for i in range(num_intersections):
        direction = random.random()
        if direction <= 0.05:
            action = 'u'
        elif 0.05 < direction <= 0.2:
            action = 'left'
        elif 0.2 < direction <= 0.4:
            action = 'right'
        else:
            action = 'straight'
        action_count[action] = action_count.get(action, 0) + 1
        
        print(i+1, SLANG[action])
    print(action_count)

drive_sim2(10)