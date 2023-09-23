#include "test.hpp"

#include <iostream>
#include <cstdlib>

int dp(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 0;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        res = max(res, dp[i]);
    }
    return res;
}

int longestIncresingNum(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 0;

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }

    for(auto x : dp) {
        cout << x << endl;
    }

    return res;
}

uint32_t bitManipulate(uint32_t start, uint32_t end) {
    uint32_t left = (1 << start) - 1;
    uint32_t right = (1 << end) - 1;

    uint32_t mask = left ^ right;

    return mask;
}

int main(void) {
    vector<int> nums = {3, 7, 0, 1, 9, 11, -2};

    // cout << longestIncresingNum(nums) << endl;
    // longestIncresingNum(nums);

    uint32_t start = 3;
    uint32_t end = 5;

    // 111   11111
    // 0011, 1000       8 + 16 + 32
    // uint32_t res = bitManipulate(start, end);
    // cout << bitManipulate(start, end) << endl;
    // printf("0x%x, %d\n", res, res);

    // res = (1 << 3) - 1;
    // uint32_t res2 = (1 << 5) - 1;
    // printf("0x%x, %d\n", res, res);
    // printf("0x%x, %d\n", res2, res2);

    uint32_t mask = 0xff;
    uint32_t val = 0x1ab;

    printf("0x%x\n", val & (~mask));

    return 0;
}