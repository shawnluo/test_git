
import unittest
from ddt import ddt, data
import HtmlTestRunner


@ddt
class TestOdd(unittest.TestCase):
 
    @data(3, 4, 12, 23)
    def runTest(self, value):
        self.assertTrue( self.NUMBER % 2 == 1, "Number should be odd")
 
