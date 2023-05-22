
import unittest
from ddt import ddt, data
import HtmlTestRunner


class TestOdd1(unittest.TestCase):
    NUMBER=1
    def runTest(self):
        """Assert that the item is odd"""
        self.assertTrue( self.NUMBER % 2 == 1, "Number should be odd")
 
class TestOdd2(TestOdd1):
    NUMBER=2


if __name__ == '__main__':
    unittest.main()
