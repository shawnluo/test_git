#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

void showMe(priority_queue<int> heap) {
    while(!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
}

int main(){
    priority_queue<int, vector<int>, less<int> > big_heap;      // 最大堆
    priority_queue<int, vector<int>, greater<int> > small_heap; // 最小堆
    priority_queue<int> heap;                                   // 默认是less - 最大堆

    heap.push(2);
    heap.push(3);
    heap.push(5);
    heap.push(0);

    big_heap.push(2);
    big_heap.push(3);
    big_heap.push(5);
    big_heap.push(0);
    
    showMe(heap);

    return 0;
}