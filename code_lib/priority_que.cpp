#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

void showMe(priority_queue<int> heap) {
    while (!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
}

int main() {
    priority_queue<int, vector<int>, less<int>> big_heap;      // 最大堆   - heap.top() 是最大值
    priority_queue<int, vector<int>, greater<int>> small_heap; // 最小堆   - heap.top() 是最小值
    priority_queue<int> heap;                                  // 默认是less - 最大堆

    heap.push(2);
    heap.push(3);
    heap.push(5);
    heap.push(0);

    big_heap.push(2);
    big_heap.push(3);
    big_heap.push(5);
    big_heap.push(0);

    // 使用 small_heap的时候，showMe函数中的参数也需要声明为greater<int>，否则会编译出错

    showMe(heap);

    return 0;
}