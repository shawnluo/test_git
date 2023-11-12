
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>



int dp_29(vector<int> nums) {
    int size = nums.size();
    vector<int> dp(size, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < size; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        cout << "i = " << i << "\t";
        cout << "dp[i - 1] = " << dp[i - 1] << "\t";
        cout << "dp[i - 2] = " << dp[i - 2] << "\t";
        cout << "nums[i] = " << nums[i] << "\t";
        cout << endl;
    }

    return dp[size - 1];
}

// i: 3    决定偷3 和不偷3      -> 3
// i: 4    决定偷4 和不偷4      -> 4
// dp[i - 2] + nums[i]: 偷i，
// dp[i - 1]: 不偷i. - 考虑了i - 1，注意只是考虑i - 1，不是一定偷i - 1


// 那么i - 2是我们考虑的范围。因为i - 1一定不能偷
// 如果考虑了i - 1

int dp_11(vector<int> weight, vector<int> value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int>(BAG, 0));

    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 1; i < weight.size(); i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else  {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[weight.size() - 1][BAG];
}

BAG = sum();
if BAG % 2 == 1 return false;
BAG = BAG / 2;
for(int i = 0; i < weight.size(); i++) {
    for(int j = BAG; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
if(dp[BAG] == BAG) return true;
return false;

left + right = sum;
abs(left - right) = S;

2 * left = sum + S;
left = (sum + S) / 2;
BAG = left;
dp[0] = 1;
for(int i = 0; i < size; i++) {
    for(int j = BAG; j >= nums[i]; j--) {
        dp[j] += dp[j - nums[i]];
    }
}

dp[0] = 1;
for(int i = 0; i <= BAG; i++) {
    for(int j = 0; j < size; j++) {
        if(i >= nums[j]) {
            dp[i] += dp[i - nums[j]];
        }
    }
    return dp[BAG];
}

vector<int> dp(BAG + 1, INT_MAX);
dp[0] = 0;
for(int i = 0; i < coins.size(); i++) {
    for(int j = 0; j * j <= i; j++) {
        if(dp[j - coins[i] != INT_MAX]) {
            dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        }
    }
}
if(dp[GAG] == INT_MAX) return -1;
return dp[GAG];

int main() {
    vector<int> nums{1, 2, 3, 1};

    cout << dp_29(nums) << endl;

    // std::string binaryFraction = "110.101"; //"11001101";
    // double decimalFraction = binaryFractionToDecimal(binaryFraction);

    // std::cout << "Binary Fraction: " << binaryFraction << std::endl;
    // std::cout << "Decimal Fraction: " << decimalFraction << std::endl;

    return 0;
}