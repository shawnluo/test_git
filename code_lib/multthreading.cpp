// C++ program to demonstrate
// multithreading using three
// different callables.
#include <iostream>
#include <thread>
using namespace std;

/**
  * 1. 调用普通函数
  * 2. 调用类符号重载函数
  * 3. 调用类成员函数
  * 4. 调用类静态成员函数
  * 5. 调用lambda
  */

// 1. A dummy function
void foo(int Z) {
    for (int i = 0; i < Z; i++) {
        cout << "Thread using function"
                " pointer as callable\n";
    }
}

// 2. A callable object
class thread_obj {
public:
    void operator()(int x) {
        for (int i = 0; i < x; i++)
            cout << "Thread using function"
                    " object as callable\n";
    }
};

// class definition
class Base {
public:
    // 3. non-static member function
    void foo();

    // 4. static member function
    static void foo1();
};

void Base::foo() {
    cout << "Thread using non-static member function "
            "as callable"
            << endl;
}

void Base::foo1() { // static类成员函数，在类外定义的时候，不能加static
    cout << "Thread using static member function as "
            "callable"
            << endl;
}

// Driver code
int main() {
    cout << "Threads 1 and 2 and 3 "
            "operating independently"
         << endl;

    // This thread is launched by using
    // function pointer as callable
    thread th1(foo, 3);

    // This thread is launched by using
    // function object as callable
    thread th2(thread_obj(), 3);

    // 5. Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "Thread using lambda"
                    " expression as callable\n";
    };

    // This thread is launched by using
    // lambda expression as callable
    thread th3(f, 3);

    // object of Base Class
    Base b;

    thread th4(&Base::foo, &b);

    thread th5(&Base::foo1);

    // Wait for the threads to finish
    // Wait for thread t1 to finish
    th1.join();

    // Wait for thread t2 to finish
    th2.join();

    // Wait for thread t3 to finish
    th3.join();

    // Wait for thread t4 to finish
    th4.join();

    // Wait for thread t5 to finish
    th5.join();

    return 0;
}