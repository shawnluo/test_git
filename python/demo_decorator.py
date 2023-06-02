
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
    # set up logging to file
    logging.basicConfig( \
        filename = 'app.log', \
        level = logging.DEBUG, \
        filemode = 'w', \
        format = '%(asctime)s - %(name)s - %(levelname)s - %(message)s', \
        datefmt = '%d-%b-%y %H:%M:%S'
        )
    
    #logger = logging.getLogger()
    
    
    #logger.warning('This will get logged to a file')
    
    #x = planet('xx')
    #logger.info(x)
    #x.static_run()
    
    # set up logging to console
    console = logging.StreamHandler()
    console.setLevel(logging.DEBUG)
    
    # set a format which is simpler for console use
    formatter = logging.Formatter('%(name)-12s: %(levelname-8s %(message)s')
    console.setFormatter(formatter)
    
    # add the handler to the root logger
    logging.getLogger('').addHandler(console)
    
    logger = logging.getLogger(__name__)
    
    x = planet('xx')
    x.static_run()