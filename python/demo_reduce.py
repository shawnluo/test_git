# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import sys
import pprint
from functools import reduce

def add(x, y) :            # 两数相加
    return x + y

'''
1. reduce默认只能取两个参数
2. 将数据安装参数表取出, 输入到func中
3. 结果会作为第一个参数输入到func中, 然后再取数据作为第二个参数
'''

sum1 = reduce(add, [1,2,3,4,5])   # 计算列表和：1+2+3+4+5
#sum2 = reduce(lambda x, y: x+y, [1,2,3,4,5])  # 使用 lambda 匿名函数
print(sum1)
#print(sum2)