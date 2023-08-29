#include "test.hpp"


// TODO: dp

// 0.                            - 01背包
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

// 9. 

// 7.1
int getLen(vector<int> nums) {
    int left = 0;
    int count = 0;

    while(left < nums.size()) {
        count++;
        int index = left + 1;

        while(index < nums.size() && nums[index] == nums[left]) {
            index++;
        }
        left = index;
    }
    return count; 
}

// 7.2
int getLen2(vector<int> nums) {
    int count = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            count++;
        }
    }
    return count;
}

// 7.3
int getLen3(vector<int> nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    return dp[nums.size() - 1];
}

// 7.4
int getLen4(vector<int> nums) {
    unordered_set<int> set;
    int res = 0;

    for(int i = 0; i < nums.size(); i++) {
        set.insert(nums[i]);
    }

    return set.size();
}

// 0
int packsack(vector<int> weight, vector<int> value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int>(BAG + 1, 0));
    int size = weight.size();
    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 1; i < size; i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[size - 1][BAG];
}

// TODO brute force - back tracking


int main(void) {
    vector<int> nums{1, 2, 3, 3, 4, 5, 5, 6};
    cout << getLen4(nums) << endl;

    return 0;
}