from functools import wraps
import inspect

class A:
    # Decorator as an instance method
    def decorator1(self, func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            print('Decorator 1')
            return func(*args, **kwargs)
        return wrapper

    # Decorator as a class method
    @classmethod
    def decorator2(cls, func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            print('Decorator 2')
            return func(*args, **kwargs)
        return wrapper
    

class B:
# As an instance method
    a = A()

    @a.decorator1
    def spam(self):
        print('spam')
        pass
    
    # As a class method
    @A.decorator2
    def grok(self, *args):
        print('grok', args[0])
        pass


x = B()
x.spam()
x.grok('dd')
print(x.grok.__name__)



