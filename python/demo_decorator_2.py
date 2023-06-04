import logging
import threading
import time
import sys

    
def use_logging(func):
    def wrapper(*args, **kwargs):
        logging.warn("%s is running" % func.__name__)
        return func(*args, **kwargs)
    return wrapper

@use_logging
def foo(*args, **kwargs):
    print("i am foo", args[0])
    for key, value in kwargs.items():
        print("%s == %s" % (key, value))



def main(argv):
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format = format, level = logging.DEBUG)

    #fun(argv)
    
    foo(111, ui = 'good')

if __name__ == "__main__":
    log = logging.getLogger("my-logger")
    main(sys.argv[1:])
    



# https://www.dusaiphoto.com/article/139/