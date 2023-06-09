import json
import pprint

class Test(object):
    @staticmethod
    def foo():
        print("starting ...")
        while True:
            res = yield 4
            print("res:", res)
        
# g = Test.foo()
# print(next(g))
# print("*"*20)
# print(next(g))
# print(next(g))
# print()

# mylist = iter(["apple", "banana", "cherry"])
# x = next(mylist)
# print(x)
# x = next(mylist)
# print(x)
# x = next(mylist)
# print(x)
# x = next(mylist)
# print(x)


class A:
    def foo(self):
        print('called A.foo()')

class B(A):
    pass

class C(A):
    def foo(self):
        print('called C.foo()')

class D(B, C): 
    pass

if __name__ == '__main__':
    d = D()
    d.foo()