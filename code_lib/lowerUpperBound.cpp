#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>


int main(void) {
    vector<int> nums = {1, 8, 9, 10, 4};
    set<int> set;
    set.insert(nums.begin(), nums.end());
    int i = 7;
    auto it1 = set.lower_bound(i);  // 获得的是大于或等于i的数据地址
    auto it2 = set.upper_bound(i);  // 获得的是大于i的数据地址

    int data;
    if(it1 != set.end()) {
        data = *it1;
        cout << data << endl;
    }

    if(it2 != set.begin()) {
        data = *(--it2);    // 要获取小于i的最大数据，需要将指针前移。
        // index = prev(it2, 1);   // 或者用prev函数
        cout << data << endl;
    }
    
    return 0;
}