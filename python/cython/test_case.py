import logging
import threading
import time
import unittest
import BeautifulReport


class myTest(unittest.TestCase):
    def test_demo1(self):
        logging.warning('Show me')
        self.assertFalse(False)

    def test_demo2(self):
        logging.warning('the monry!')
        self.assertTrue(True)
        