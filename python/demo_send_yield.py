# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import sys
import pprint

def consumer():
   r = 'here'
   while True:
       n1 = yield r   #这里的等式右边相当于一个整体，接受回传值
       if not n1:
           return
       print('[CONSUMER] Consuming %s...' % n1)
       r = '%d00 OK' % n1

def produce(c):
    aa = c.send(None)
    n = 0
    while n < 5:
        n = n + 1
        print('[PRODUCER] Producing %s...' % n)
        r1 = c.send(n)
        print('[PRODUCER] Consumer return: %s' % r1)
    c.close()

c = consumer()
produce(c)