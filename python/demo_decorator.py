
import logging
import os
import sys

'''
def foo():
    print('foo')
    
def bar(func):
    func()
    
bar(foo)
'''

class planet:
    def __init__(self, astring):
        self.s = astring
        logging.info('planet - init')
        
    @staticmethod
    def static_run():
        logging.info('planet - static')
        
    @classmethod
    def class_run(cls, x):
        logging.info(f"planet - class({cls}, {x})")
        
        
if __name__ == '__main__':
    #logging.basicConfig(level = logging.INFO)
    logging.basicConfig(filename='app.log', \
        filemode='w', \
        format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', \
        datefmt='%d-%b-%y %H:%M:%S')
    
    logger = logging.getLogger()
    logger.setLevel(logging.DEBUG)
    
    logger.warning('This will get logged to a file')
    
    x = planet('xx')
    logger.info(x)
    x.static_run()