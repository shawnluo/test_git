
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>

void test() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(12);
    pq.push(11);
    pq.push(111);

    cout << pq.top() << endl;
    
    while(!pq.empty()) {
        pq.pop();
    }
    assert(pq.empty());

    // cout << pq.top() << endl;
}


int main() {
    test();

    return 0;
}



