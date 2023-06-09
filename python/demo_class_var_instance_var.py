# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import pprint

class A(object):
    va = 10

    def foo(self):
        print (A.va)
        print (self.va)

        self.va = 40
        print ('A.va', A.va)
        print ('self.va', self.va)

        A.va = 60
        print ('A.va', A.va)
        
        va = 20
        print ('va', va)

        A.va = 15
        print ('A.va', A.va)
        print ('self.va', self.va)

# Script starts from here

obj1 = A()
obj2 = A()
obj1.foo()

print(obj1.__dict__)

print (A.va)
print (obj1.va)
print (obj2.va)