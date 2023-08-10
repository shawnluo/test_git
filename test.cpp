#include "test.hpp"



//TODO: find the smallest difference between 2 elements in a unsorted array
// 1. use normal way
int minDif(vector<int> nums) {
    int res = INT_MAX;
    int len = nums.size();
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < i; j++){
            res = min(abs(nums[i] - nums[i - 1]), res);
        }
    }
    return res;
}

// 2. use dp 
// 这与上面的常规方法的思路截然不同。
//      dp: 当取 0 ~ i时，两数的差最小值
int minDif_dp(vector<int> nums) {
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    dp[1] = abs(nums[0] - nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        for(int j = 1; j < i; j++) {
            // dp[i] = min(dp[i], min(dp[i - j], abs(nums[i] - nums[j])));
            dp[i] = min(dp[i], min(dp[j], abs(nums[i] - nums[j])));
        }
    }
    return dp[nums.size() - 1];
}

int countValidPairs(vector<int> nums, int threshold) {
    int len = nums.size();
    int i = 0;
    int count = 0;
    while(i < len - 1) {
        if(nums[i + 1] - nums[i] <= threshold) {
            i++;
            count++;
        }
        i++;
    }
    return count;
}

int findMaxInMinDiff(vector<int> nums, int p) {
    std::sort(nums.begin(), nums.end());
    int len = nums.size();
    int left = 0;   // we can start from nums[1] - nums[0], but from 0 can simplify the code
    int right = nums[len - 1] - nums[0];

    while(left < right) {
        int mid = (left + right) / 2;
        if(countValidPairs(nums, mid) >= p) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(void) {
    vector<int> nums = {10, 9, 4, 15, 25, 68};

    // cout << findMaxInMinDiff(nums, 3) << endl;
    cout << minDif_dp(nums) << endl;
    // printf("%d\n", rmDup(arr, 5));

    return 0;
}