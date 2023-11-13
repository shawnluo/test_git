
#include "test.hpp"

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
            dp[i][0] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1]});
            dp[i][1] = max({dp[i][0], dp[i - 1][0], dp[i - 1][1]});
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