from demo_decorator import planet
import inspect
#from decorator import decorator
import time


x = None

def my_decorator(func):
    def wrapper():
        print('11')
        res = func()
        print('22')
        print('res =', res)
        print('res = {:.4}'.format(res))
        return res
    return wrapper


@planet.do_twice
@my_decorator
def say_whee():
    t1 = time.time()
    print('33')
    time.sleep(2)
    t2 = time.time()
    return t2 - t1


def main():
    res = say_whee()
    print('res =', res)
    #print('res = {:.4}'.format(res))
    print (say_whee.__name__)
    print (inspect.getfullargspec(say_whee))
    #print (inspect.signature(say_whee))
    
    #count = planet.count_prime_nums(1000)


if __name__ == '__main__':
    main()
