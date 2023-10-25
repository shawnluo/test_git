#include "test.hpp"


int dp_41(vector<int> nums) {
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
    return res;
}

int res = 1;
vector<int> dp(nums.size(), 1);
for(int i = 1; i < nums.size(); i++) {
    if(nums[i] > nums[i - 1]) {
        dp[i] = dp[i - 1] + 1;
    }
    res = max(res, dp[i]);
}
return res;

int k = 1;
for(int i = 1; i < nums.size(); i++) {
    for(int j = 0; j < i; j++) {
        if(nums[i] == nums[j]) {
            break;
        }
    }
    if(i == j) {
        nums[k++] = nums[i];
    }
}

