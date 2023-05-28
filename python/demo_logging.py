import logging
import threading
import time

def fun():
    logging.debug('debug - fun - 1')

def main():
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format)#, level=logging.DEBUG)

    #logging.basicConfig(format=format, level=logging.INFO,
    #                    datefmt="%H:%M:%S")

    logging.warning("warning - 111")
    logging.info("info - 222")
    logging.error("error - 333")
    logging.debug("debug - 444")

    fun()

if __name__ == "__main__":
    log = logging.getLogger("my-logger")
    main()

'''


# Import logging.handlers module
import logging.handlers
# Create the demo handler
demoHandler = logging.handlers.HTTPHandler('logs-00.loggly.com', '/inputs/<TOKEN>/tag/http/', method= 'POST')
logger = logging.getLogger()
# Add the handler we created
log = logger.addHandler(demoHandler)
# Emit a log message
logger.warning("Warning Message!")
'''