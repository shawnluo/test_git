

#include "../test.hpp"

// 最长递增子序列 - 非连续

int longest_increasing_nums(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 0;
    // dp[i]: 
    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }
    return res;
}