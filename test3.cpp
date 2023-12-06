#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

#include <iostream>
#include <string>


#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

atomic_flag flag;
int a = 0;

void foo() {
    for (int i = 0; i < 10000000; ++i) {
        while (flag.test_and_set()) {

        } //加锁
        a += 1;
        flag.clear(); //解锁
    }
}

int main() {
    flag.clear(); //初始化为clear状态

    clock_t start, end;
    start = clock();
    thread t1(foo);
    thread t2(foo);
    t1.join();
    t2.join();
    end = clock();
    cout << a << endl;
    cout << end - start << endl;
    return 0;
}