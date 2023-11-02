
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


void showme(vector<int>& nums) {
    nums[2] = 100;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    showme(nums);
    cout << nums[2] << endl;

    return 0;
}