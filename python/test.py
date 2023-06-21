# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import sys
import pprint
from functools import reduce
import os

res = os.path.exists('./test') # if folder exist
print(res)

res = os.path.isfile('./test.py')
print(res)