#include "test.hpp"

/*
1, 1, 1, 1, 1
1, 1, 1, 2
2, 2, 1
5
*/
// return the number of combinations that make up that amount.
int dp_19(vector<int> coins, int amount) {
    // dp[j]: pickup from [0, i], makeup j, the combinations
    // 完全背包问题, 背包容量为j, 从[0, i]中取有多少种方法

    vector<int>dp(amount + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++) {
        // for(int j = coins[i]; j <= amount; j++) {
        for(int j = 0; j <= amount; j++) {
            if(j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[amount];
}

int dp_21(vector<int> coins, int amount) {
    // dp[j]: pickup from [0, i], makeup j, how many permutation
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for(int i = 0; i <= amount; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
            }
        }
    }
    return dp[amount];
}

// return the fewest number of coins that you need to make up that amount.
int dp_23(vector<int> coins, int amount) {
    // dp[i]: the fewest number of coins[0, j], to makeup the i
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++) {
        for(int j = 0; j <= amount; j++) {
            if(dp[j - coins[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// 2.
vector<vector<int>> res;
vector<int> buf;

void do_combine(int n, int k, int pos) {
    if(buf.size() == k) {
        res.push_back(buf);
        return;
    }
    for(int i = pos; i <= n; i++) {
        buf.push_back(i);
        do_combine(n, k, pos + 1);
        buf.pop_back();
    }
}

// return all possible combinations of k numbers chosen from the range [1, n]
// n = 4, k = 2
// [1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]
vector<vector<int>> combine(int n, int k) {
    do_combine(n, k, 1);

    return {};
} 

int main(void) {
    // vector<int> coins{10, 20, 15, 5};
    // int amount = 25;
    // cout << dp_23(coins, amount) << endl;

    buf.clear();
    res.clear();
    combine(4, 3);

    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}