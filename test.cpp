#include "test.hpp"

#if 0
// 1
int longest_uniq_str(string s) {
    int len = s.size();
    vector<int> hash(256, -1);
    int pos = -1;
    int len_max = 0;
    for(auto i = 0; i < len; i++) {
        pos = max(pos, hash[s[i]]);
        len_max = max(len_max, i - pos);
        hash[s[i]] = i;
    }
    return len_max;
}

int main(void) {
    string s = "abcaxyz";
    int res = longest_uniq_str(s);
    cout << res << endl;

    return 0;
}

#endif

#if 0
// 2
// combine
vector<vector<int>> res;
vector<int> path;

void combine(int x, int k, int indexStart) {
    if(path.size() == k) {
        res.push_back(path);
        return;
    }
    for(auto i = indexStart; i < k; i++) {
        path.push_back(i);
        combine(x, k, i + 1);
        path.pop_back();
    }
}

int main(void) {
    vector<string> res;
    string s = "abcd";
    // vector<string> _res = 
    permu(s, 0, res);

    for(auto x : res) {
        cout << x << endl;
    }

    return 0;
}
#endif

#if 0
// 3
// how many ways to reach to the ladder top
int ladder(const int n) {
    if(n <= 1) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for(auto i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
#endif

#if 0
// 4
// you can start from 0 or 1
// the minimal cost to reach to the ladder top
int ladder_cost(const vector<int> cost) {
    // cost[]
    int len = cost.size();
    vector<int> dp(len + 1)
    // 1. dp formular
    // dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]; 

    // 2. initlization
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = cost[2];

    // 3. loop
    for(auto i = 3; i <= len; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2]) + cost[i - 2];
    }
    return dp[len];
}
#endif

#if 0
// 5
int robot_paths(int m, int n) {
    vector<vector<int>> dp([m], vector<int>(n, 0));

    // 1. formular
    // dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    // 2. initialization
    // if(i == 0 || j == 0) {
    //     dp[i][j] = 1;
    // }

    // 3. for loop
    for(auto i = 0; i < m; i++) {
        for(auto j = 0; j < n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
#endif

#if 0
// 6
int robot_obstacles(const vector<vector<int>> obstacle) {
    int m = obstacle.size();
    int n = obstacle[0].size();

    vector<vector<int>> dp(m, vector<int> (n, 0));
    // 1. formular
    // if(obstacle[i][j] == 1) {continue;}
    // dp[i][j] = dp[i][j - 1] + dp[i - 1][j];

    // 2. initialization
    for(auto i = 0; i < m; i++) {dp[i][0] = 1;}
    for(auto j = 0; j < m; j++) {dp[0][j] = 1;}

    // 3. for loop
    for(auto i = 1; i < m; i++) {
        for(auto j = 1; j < n; j++) {
            if(obstacle[i][j] == 1) {continue;}

            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[m - 1][n - 1];
}
#endif

#if 0
// 7
int interBreak(int num) {
    // 1. formular
    // dp[i]: the ways break i - [1, i)
    // dp[i] = max(dp[i - j] * j, (i - j) * j)

    // 2. initialization
    // dp[1] = 0
    // dp[2] = 1

    // 3. for loop
    for(auto i = 3; i <= num; i++) {
        for(auto j = 1; j < i - 1; j++) {
            dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
        }
    }
    return dp[num];
}
#endif

#if 0
// 8
class Solution {
public:
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    int backpack() {
        // 0.
        vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));   // define dp

        // 1. initialization
        for(auto j = weight[0]; j <= bagWeight; j++) {
            if (j < weight[0]) {
                dp[0][j] = value[0];
            }
        }

        // 2. formular
        for(auto i = 0; i < weight.size(); i++) {
            for(auto j = 0; j <= bagWeight; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[j]] + value[i]);
            }
        }

        // dp[i]
    }
};


// i: 选取物品， 从 0 ~ i
// j: 背包容量
// dp[i][j]: 物品最大价值

for(j = w[0]; j <= BAG; j++) {
    dp[0][j] = v[0];
}

dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])

for(i = 1; i < size; i++) {
    for(j = 0; j <= BAG; j++) {
        if(j < w[i]) {
            dp[i][j] = dp[i - 1][j];
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
}

// j: 背包容量
// dp[j]: 背包内物品最大值
dp[j] = max(dp[j], dp[j - W[i]] + V[i]);

for(int i = 0; i < size; i++) {
    for(int j = bagWeight; j >= W[i]; j--) {
        dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
    }
}

int main(void) {
    Solution sol;
    sol.backpack();
}
#endif

//TODO backtrack to get list
#if 1
class Solution {
public:

    int break_int(const vector<int> n) {
        // i: choose [item[0], item[i - 1])
        // j: backpack capacity j
        // dp[i][j]: the maximum of sum of items put into j

        int len = n.size();
        int sum = 0;
        for(auto x : n) {
            sum += x;
        }
        int target = sum / 2;
        cout << target << endl << endl;

        vector<int> dp(1000, 0);
        for(auto i = 0; i < len; i++) {
            for(auto j = target; j >= n[i]; j--) {
                dp[j] = max(dp[j], dp[j - n[i]] + n[i]);
            }
        }

        for(auto x = 0; x <= n[len - 1]; x++) {
            cout << dp[x] << endl;
        }
        return 0;
    }

    void trackBack() {

    }
};

int main(void) {
    Solution solution;

    vector<int> n{1, 5, 5, 3, 9};
    solution.break_int(n);
    return 0;
}
#endif