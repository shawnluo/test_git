#include "test.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// [2, 7, 4, 1, 8, 1] sum = 23   half = 11.5

class Solution {
    public:
#if 0
    int split_group() {
        vector<int> num{ 1, 3, 9, 2, 5 };
        int size = num.size();


        int half = 0;
        for (auto x : num) {
            half += x;
        }
        if (half % 2) return 0;
        half /= 2;
        vector<int> dp(half, 0);

        for (int i = 0; i < size; i++) {
            for (int j = half; j >= num[i]; j--) {
                dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
            }
        }
        if (dp[half] == half) return 1;

        return 0;
    }

    int coin_change() {
        vector<int> coins = { 1, 2, 5 };
        int sum           = 4;

        vector<int> dp(coins.size(), 0);
        // dp[j] += dp[j - coins[i]];
        return 0;
    }

    // a b c
    // a b c    子集
    // b a c    子集
    // c b a    子集
    void permutation(string s, int pos) {
        if (pos >= s.size()) {
            cout << s << endl;
        }
        for (int i = pos; i < s.size(); i++) {
            if (i != pos && s[i] == s[pos]) continue;
            swap(s[i], s[pos]);
            permutation(s, pos + 1);
            swap(s[i], s[pos]);
        }
    }
#endif

    // 1, 2, 3, 4
    // 2
    // 1
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int num, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (auto i = startIndex; i <= num; i++) {
            path.push_back(i);
            backtracking(num, k, startIndex + 1);
            path.pop_back();
        }
    }

    //-------------------------
    vector<vector<int>> ans;
    vector<int> cur;

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }

    void dfs(int start, int n, int k) {
        if (k == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            dfs(i + 1, n, k - 1);
            cur.pop_back();
        }
    }

    // --------------------------
    vector<int> twoSum(const vector<int> nums, const int target) {
        vector<int> dp(target + 1, 0);
        // vector<int> chosen(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                // chosen[i] = true;
            }
        }
        for (auto x : dp)
            cout << x << endl;

        // for(auto x : chosen) {
        //     cout << x << endl;
        // }
        return dp;
    }

    // --------------------------------------
    vector<int> twoSum_x(const vector<int>& nums, const int target) {
        unordered_map<int, int> numMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                result.push_back(i);
                result.push_back(numMap[complement]);
                break;
            }
            numMap[nums[i]] = i;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    // int res = solution.coin_change();
    // cout << res << endl;
    // string s = "aaa";
    // solution.permutation(s, 0);

    // vector<vector<int>> ans = solution.combine(3, 2);
    // for (auto x : ans) {
    //     for(auto y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }

    vector<int> nums{ 4, 2, 7, 51 };
    int target = 9;
    vector<int> result = solution.twoSum_x(nums, target);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}