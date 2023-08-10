#include "/home/rain/workSPACE/test_git/test.hpp"

// 1. use the normal way: 
int minDif(const vector<int> nums) {
    int res = INT_MAX;

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            res = std::min(res, std::abs(nums[i] - nums[j]));
        }
    }
    return res;
}


// 2. dp
// 这与上面的常规方法的思路截然不同。
//      dp: 当取 0 ~ i时，两数的差最小值
int minDif2(vector<int> nums) {
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    dp[1] = abs(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        for(int j = 1; j < i; j++) {
            dp[i] = min(dp[i], min(dp[j], abs(nums[i] -nums[j])));   //先与dp[j]依次比较，然后再自身迭代比较。
        }
    }
    return dp[nums.size() - 1];
}


// 3. sort first: 
int minDif3(vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    int res = INT_MAX;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] - nums[i - 1]) {
            res = std::min(res, nums[i] - nums[i - 1]);
        }
    }
    return res;
}

