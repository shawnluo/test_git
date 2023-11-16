
#include "test.hpp"

/*
152. Maximum Product Subarray

Medium

Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

class Solution {
public:
    static int maxProduct_DP(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int res = dp[0][1];

        for(int i = 1; i < size; i++) {
            dp[i][0] = min({nums[i], dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]});
            dp[i][1] = max({nums[i], dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]});
            res = max(res, dp[i][1]);
        }
        return res;
    }

    static int maxProduct_BF(vector<int>& nums) {
        int pro;
        int size = nums.size();
        int res  = nums[0];

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                pro = 1;
                for (int k = i; k <= j; k++) {
                    pro *= nums[k];
                }
                res = max(res, pro);
            }
        }

        return res;
    }
};


int main(void) {
    vector<int> nums{ 2, 3, -2, 4 };
    cout << Solution::maxProduct_DP(nums) << endl;

    return 0;
}