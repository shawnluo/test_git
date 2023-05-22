
import unittest
from ddt import ddt, data
import HtmlTestRunner




class ParametrizedTestCase(unittest.TestCase):
    """ TestCase classes that want to be parametrized should
        inherit from this class.
    """
    def __init__(self, methodName='runTest', param=None):
        super(ParametrizedTestCase, self).__init__(methodName)
        self.param = param
 
    @staticmethod
    def parametrize(testcase_klass, param=None):
        """ Create a suite containing all tests taken from the given
            subclass, passing them the parameter 'param'.
        """
        testloader = unittest.TestLoader()
        testnames = testloader.getTestCaseNames(testcase_klass)
        suite = unittest.TestSuite()
        for name in testnames:
            suite.addTest(testcase_klass(name, param=param))
        return suite


class my_test(ParametrizedTestCase):
    def test_001(self):
        print( 'param =', self.param)
        self.assertEqual(1, 1)
 
    def test_002(self):
        self.assertEqual(2, 2)


if __name__ == '__main__':
    '''
    suite = unittest.TestSuite()
    suite.addTest(ParametrizedTestCase.parametrize(TestOne, param=42))
    suite.addTest(ParametrizedTestCase.parametrize(TestOne, param=13))
    unittest.TextTestRunner(verbosity=2).run(suite)

    '''

    '''
    runner_setting = HtmlTestRunner.HTMLTestRunner(combine_reports = True, \
        output = 'result', \
        report_name = 'demo_report', \
        add_timestamp = False)
    testMain = unittest.main(testRunner = runner_setting)
    '''

    # 1、 创建 TestSuite
    suite = unittest.TestSuite()

    # 2。 添加测试用例 类名称("方法名称")
    #suite.addTest(my_test1("test_001"))
    suite.addTest(ParametrizedTestCase.parametrize(my_test, param=42))
    #suite.addTest(my_test1("test1_002"))
    # 2. 或者用 unittest.makeSuite(类名) 添加所有的方法
    #suite.addTest(unittest.makeSuite(my_test1))

    # 3. 定义个报告存放的路径，支持相对路径
    file_path = "./result.html"
    file_result = open(file_path, 'wb')

    # 定义测试报告
    runner = HtmlTestRunner.HTMLTestRunner(combine_reports = True, \
                output = 'result', \
        report_name = 'demo_report', \
        add_timestamp = False)
    runner.run(suite)  # 调用对象的run方法
    file_result.close()