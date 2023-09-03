#include "test.hpp"


// TODO: dp

// 0.                            - 01背包
    // 1. 二维数组
    // 2. 一维滚动数组 - 也就是把二维数组数据压缩到只有一行。重复使用这一行数据(就是carl所说的拷贝)：
            // 1. 从上次的数据取值，将本次计算后的值，覆盖掉本行。因为二维数组的行列矩阵数据只被斜下部的单元使用。
            // 2. j需要倒序。因为根据dp[j] = dp[j - weight[i]] + value，dp[j]是一维的，其取值是根据左边的数据来获取的。
                // 如果从左边开始循环，那么左边的取值会被不断重复计入。从而影响结果。
                // 如果从右边开始循环，因为左边的元素都是初始值0。其不会影响计算结果！
                // 对比二维数组，其数据都是独立存在的，没有被重复使用。

// 1. 装满背包的最大价值是多少？    - 纯完全背包
// 2. 装满背包有多少种方法？求组合  - 零钱兑换2
// 3. 装满背包有多少种方法？求排列  - 组合总和4
// 4. 装满背包最少用多少个物品？    - 322零钱兑换

// 5. 最长连续上升子序列
    // 1）. 长度
    // 2）. 打印出上升子序列

// 6. 最长上升子序列
    // 1）. 长度
    // 2）. 打印出上升子序列

// 7. 排序后的单元的序列长度
    // 1). 双指针去重
    // 2). 判断与前一个数不相等
    // 3). 除重后的长度 - dp解
    // 4). 打印除重后的序列 - unordered_set

// 8. 未排序后的单元的序列长度
    // 1）. 除重后的长度
        // 1. dp
        // 2. while loop delete
    // 2）. 打印除重后的序列

// 9. leetcode 1091 - the shortest path in binary matrix
    // 1. BFS - breadth-first search

// 24 完全平方数
// dp[j] = min(dp[j], dp[j - i * i] + 1)

// bagsack 0-1
int bagsack(vector<int> weight, vector<int> value, int BAG) {
    // dp[i][j]: choose from 0-i item, put into j cap, the max value
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

    int size = weight.size();
    vector<vector<int>> dp(size, vector<int>(BAG + 1, 0));
    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }
    for(int i = 1; i < size; i++) {
        // for(int j = weight[i]; j <= BAG; j++) {
        for(int j = 1; j <= BAG; j++) {
            if(j < weight[i]) { // 背包装不下当前的物品，即weight[i]，那就等于上一个dp，也就是dp[i - 1]
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                // dp[1 - 1][3], dp[1 - 1][3 - 3] + 20
                // dp[1 - 1][4], dp[1 - 1][4 - 3] + 20 --- 15 + 20
            }
        }
    }
    for(auto x : dp) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return dp[size - 1][BAG];
}

// dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

int coinChanges(vector<int> coins, int amount) {
    int size = coins.size();
    vector<int> dp(amount + 1, INT_MAX);    // the minimal coin numbers of change i
    // dp[j] = min(dp[j], dp[j - coins[i]] + 1)
    dp[0] = 0;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j <= amount; j++) {
            if(dp[j - coins[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    return dp[amount];
}

int main(void) {
    vector<int> weight{1, 3, 4, 8};
    vector<int> value{15, 20, 30, 40};
    int BAG = 4;
    cout << bagsack(weight, value, BAG) << endl;

    return 0;
}

// 1. 0-1 bagsack
// pick from items[0, i], put into BAG, what's the most value. cannot pick the same item
int DP_1(vector<int> weight, vector<int> value, int BAG) {
    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

// 2. complete pack
// pick from items[0, i], put into BAG, what's the most value. repeatly pick the same item is allowed.
int DP_2(vector<int> weight, vector<int> value, int BAG) {
    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = 0; j <= BAG; j++) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

// 3. combination
// there are different value coins, and amount
// how many ways to makeup the amount
// infinity amount of each coins
int DP_3(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, 0); // dp[j]: the ways to fill knapSack j
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++) {     // TODO 1. loop starts from? from 0
        for(int j = 1; j <= amount; j++) {      // TODO 2. loop starts from? from 1 or coins[i]
            // if(j < coins[i]) {               // TODO 3. condition? if from 1, then if(j < coins[i]), so can be skipped
                // dp[j] = dp[j - 1];           // TODO 4. what the solution under this condition? dp[j] = dp[j - 1]
            // } else {
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[amount];
}

// 4. permutation - 组合总数IV
// given an array of distinct integers nums and a target.
// return the number of possible combination that add up to target
int DP_4(vector<int> nums, int amount) {
    vector<int> dp(amount + 1, 0);
    // dp[i]: the permutation of choosen from nums[0, i]
    dp[0] = 1;
    for(int i = 0; i <= amount; i++) {
        for(int j = 0; j <= amount; j++) {
            if(i >= nums[j] && \
                dp[i] + dp[i - nums[j]] < INT_MAX) {    // 不作要求！但是此题目中提到了两个数相加可能超出计数范围的情况
                dp[i] += dp[i - nums[j]];
            }
        }
    }
}


// 5. least items to fill the knapsack
// different value of coins, and amount
// the minimal coins to makeup the amount
int DP_5(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            if(dp[j - coins[i]] != INT_MAX) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    if(dp[amount] == INT_MAX) {
        return -1;
    }
    return dp[amount];
}