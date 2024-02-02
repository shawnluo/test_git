# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import sys
import pprint
from functools import reduce
import os

class Employee:
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@company.com'
        
emp_1 = Employee('Corey', 'Schafer', 50000)
emp_2 = Employee('Mike', 'Wallace', 60000)

print(emp_1.email)
print(emp_2.email)
print('{}')


res = os.path.exists('./test') # if folder exist
print(res)

res = os.path.isfile('./test.py')
print(res)

