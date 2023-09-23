#include "test.hpp"

// 最长连续增长子序列
int longest_Increasing_nums_consectively(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 0;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;  // 这里不用取dp[i]的最大值。 dp[i] = max(dp[i], dp[i - 1] + 1)
        }
        res = max(res, dp[i]);
    }
    return res;
}