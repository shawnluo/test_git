#include "test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>


#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int findOdd(vector<int>& nums) {
    int res = 0;

    for(auto it : nums) {
        res ^= it;
    }
    return res;
}

int main(void) {
    int res = 0;
    vector<int> nums = {1, 2, 3, 2, 3, 1, 3};
    res = findOdd(nums);

    cout << res << endl;

    return 0;
}