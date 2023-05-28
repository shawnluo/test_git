import logging
import threading
import time
import unittest
import BeautifulReport
import sys



def thread_function(name):
    #logging.info("Thread %s: starting", name)
    logging.debug("Thread %s: starting", name)
    time.sleep(2)
    logging.info("Thread %s: finishing", name)

if __name__ == "__main__":
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.DEBUG,
                        datefmt="%H:%M:%S")

    #logging.info("Main    : before creating thread")
    
    args = sys.argv[1:]

    param = [args[0] + ',' + args[2], args[1] + ',' + args[2]]
    
    #x = param.split(',')[0]
    for item in param:
        #print(item)
        s1 = item.split(',')[0]
        s2 = item.split(',')[1]
        print(s1)
        print(s2)
    
    sys.exit(0)
    for index in range(2):
        x = threading.Thread(target=thread_function, args=(param[index],))

        #threads.append(x)
        x.start()
        time.sleep(5)
                
    #for index, thread in enumerate(threads):
        #thread.join()