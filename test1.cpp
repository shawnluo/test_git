
#include "test.hpp"


int main() {
    int x = 10;
    
    // lambda表达式无法修改通过复制形式捕捉的变量, 因为函数调用运算符的重载方法是const属性的。
    // 有时候，你想改动传值方式捕获的值，那么就要使用mutable, 将函数调用运算符变成非const属性的：
    auto add_x = [&x](int a) mutable { x *= 2; return a + x; };  // 复制捕捉x
    
    cout << add_x(10) << endl; // 输出 30
    cout << x << endl;
    return 0;
}
