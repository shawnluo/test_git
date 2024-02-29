# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import sys
import pprint
from functools import reduce
import os
import random

from collections import deque
from transformers import pipeline

classifier = pipeline("sentiment-analysis")
res = classifier("Today is a nice day!");
print(res)