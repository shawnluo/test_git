#include <iostream>
using namespace std;
class test
{
public:
    int a;
    double b;
    string c;
};

int main() {
    test t;
	
    //第一种，c++提供的类成员指针
    int test::*p = &test::a;
    double test::*q = &test::b;
    string test::*m = &test::c;
    t.*p = 5;
    t.*q = 2.2;
    t.*m = "hello";
    cout << t.a << endl;//5
    cout << t.b << endl;//2.2
    cout << t.c.c_str() << endl;//hello

    //第二种
    t.*(&test::a) = 6;
    cout << t.a << endl;//6

    //第三种
    cout << (size_t)(&((test*)0)->b) << endl;//8,成员b的偏移量
    size_t gg = (size_t)(&t)+ (size_t)(&((test*)0)->b);
    cout << (void*)&t << ":" << (void*)gg << endl;//0041F7EC::0041F7F4,对象的地址，对象成员偏移后的地址
    *(double*)gg = 9.9;
    cout << t.b << endl;//9.9,可见对象可以通过偏移量找到成员并操作它的成员
  
    return 0;
}