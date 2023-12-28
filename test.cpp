


#include "test.hpp"
#include <thread>

using namespace std;
 
/* TODO
    1. 🔥   find island
    2. 🔥   decimal to bin c/c++
    3. bin to decimal c/c++
    4. blur
    5. memcpy
    6. memcpy align
    7. delete extra spaces in a string
    8. robbing houses
    9. rangeBitwiseAnd
 */

int dp_8(int n) {
    if(n <= 0) return 0;
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    // dp[i] = max(dp[i - j] * j, (i - j) * j)
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
        }
    }
}

int dp_11(vector<int> weight, vector<int> value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int> (BAG + 1, 0));
    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }
    for(int i = 0; i < weight.size(); i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[weight.size() - 1][BAG];
}

int dp_12(vector<int> weight, vector<int> value, int BAG) {
    vector<int> dp(BAG + 1 , 0);

    for(int i = 0; i < weight.size(); i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

int dp_29(vector<int> nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        cout << dp[i - 2] + nums[i] << " - " << dp[i - 1] << endl;
    }
    return dp[nums.size() - 1];
}

int dp_23(vector<int>& coins, int BAG) {
    int n = coins.size();
    vector<int> dp(BAG + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= BAG; j++) {
            // if(dp[j - coins[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - coins[j - i * i]] + 1);
        }
    }
    return dp[BAG];
}

int main(void) {
    vector<int> nums = {1, 2, 5};
    cout << dp_23(nums, 11) << endl;

    // vector<int> nums = {2, 7, 9, 3, 1};
    // cout << dp_29(nums) << endl;

    // string s = "abaac";
    // vector<int> neededTime = {1,2,3,4,5};
    // cout << minCost(s, neededTime) << endl;
    // int x = 0b110;
    // string s = "1101.111";
    // double res = binaryFractionToDecimal(s);
    // cout << res << endl;

    // int2Bin(12);

    // string s = "   ab cd     x y cc  exit   ";
    // delExtraSpaces(s);
    // cout << "OOO" << s << "OOO" << endl;

    return 0;
}