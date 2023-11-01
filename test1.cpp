
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    }
};

vector<int> sort(vector<int>& nums) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
    unordered_set<int> res;

    for(auto it = map.begin(); it != map.end(); it++) {
        pri_que.push(*it);
        if(res.size() > 2) {
            pri_que.pop();
        }
    }

    vector<int> res_;
    
    while(!pri_que.empty()) {
        cout << pri_que.top().first << " ";
        
        res.insert(pri_que.top().first);
        pri_que.pop();
    }
    cout << endl;

    for(auto it = res.begin(); it != res.end(); it++) {
        // cout << *it << " ";
    }
    // cout << endl;

    return res_;
}


void showMe(priority_queue<int> heap) {
    while(!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
}

int main(){
    vector<int> nums = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    sort(nums);

    // priority_queue<int, vector<int>, less<int> > big_heap;      // 最大堆
    // priority_queue<int, vector<int>, greater<int> > small_heap; // 最小堆
    // priority_queue<int> heap;                                   // 默认是less - 最大堆

    // heap.push(2);
    // heap.push(3);
    // heap.push(5);
    // heap.push(0);
    // heap.push(0);
    // heap.push(0);
    // heap.push(3);

    // big_heap.push(2);
    // big_heap.push(3);
    // big_heap.push(5);
    // big_heap.push(0);
    
    // showMe(heap);

    return 0;
}