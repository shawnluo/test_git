#include <iostream>
using namespace std;

namespace MyNamespace {
    int myInt = 1;
    void myFunction() {}
}
 
class MyClass {
public:
    static int myStaticInt;
    void myMethod() {
        // 使用双冒号指定调用 MyNamespace 命名空间的 myFunction 函数
        MyNamespace::myFunction();
        // 使用双冒号指定访问 MyNamespace 命名空间的 myInt 变量
        int x = MyNamespace::myInt;
    }
};
 
// 使用双冒号指定定义 MyClass 的静态成员 myStaticInt
int MyClass::myStaticInt = 0;
 
// 使用双冒号指定访问 MyClass 的静态成员 myStaticInt
int x = MyClass::myStaticInt;

int main() {
	return 0;
}