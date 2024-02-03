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


myTuple = ('apple', 3, 'banana', 'cherry', 2.12)
print(myTuple)