
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


#include <iostream>
#include <string>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// 正常的类模板
template <typename T1, typename T2>
class Operator {
public:
    void add(T1 a, T2 b) {
        cout << "add(T1 a, T2 b)" << endl;
        cout << a + b << endl;
    }
};

// 部分特化的类模板，当两个参数都一样，调用这个
template <typename T>
class Operator<T, T> {
public:
    void add(T a, T b) {
        cout << "add(T a, T b)" << endl;
        cout << a + b << endl;
    }
};

// 部分特化的类模板，当两个参数都是指针，调用这个
template <typename T1, typename T2>
class Operator<T1*, T2*> {
public:
    void add(T1* a, T2* b) {
        cout << "add(T1* a, T2* b)" << endl;
        cout << *a + *b << endl;
    }
};

// 完全特化的类模板，当两个参数都是void*，调用这个
template <>
class Operator<void*, void*> {
public:
    void add(void* a, void* b) {
        cout << "add(void* a, void* b)" << endl;
        cout << "add void* Error" << endl;
    }
};

int main() {
    int *p1 = new int(1);
    float *p2 = new float(1.25);

    Operator<int, float> Op1;   // 匹配正常的类模板: class Operator
    Op1.add(1, 1.5);

    Operator<int, int> Op2;     // 匹配部分特化的类模板: class Operator<T, T>
    Op2.add(1, 4);

    Operator<int*, float*> Op3; // 匹配部分特化的类模板: class Operator<T1*, T2*>
    Op3.add(p1, p2);

    Operator<void*, void*> Op4; // 陪陪完全特化的类模板: class Operator<void*, void*>
    Op4.add(nullptr, nullptr);

    delete p1;
    delete p2;

    return 0;
}

template<typename T>
struct TREE {
    T data;
    TREE* left;
    TREE* right;
    TREE(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
using Tree = TREE<T>;

template<typename T>
using pTree = TREE<T>*;