#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>


// C++ program to demonstrate
// multithreading using three
// different callables.
#include <iostream>
#include <thread>
using namespace std;

/* 四、编写一个程序，开启3个线程，
    这3个线程的ID分别为A、B、C，
    每个线程将自己的ID在屏幕上打印10遍，
    要求输出结果必须按ABC的顺序显示；如：ABCABC….依次递推。 */

#define NUM 3
int n = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //互斥量
pthread_mutex_t qready = PTHREAD_COND_INITIALIZER; // 条件互斥量


void *thread_func(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        cout << "A" << endl;
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    int i;
  return 0;
}