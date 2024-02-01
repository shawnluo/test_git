from collections import deque

class A:
    def add(self, x):
        y = x + 1
        print(y)
        
class B(A):
    def add(self, x):
        super().add(x)  # 调用父类中的add函数

b = B()
b.add(4)