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
    // 1）. 除重后的长度 - dp解
    // 2）. 打印除重后的序列

// 8. 未排序后的单元的序列长度
    // 1）. 除重后的长度
        // 1. dp
        // 2. while loop delete
    // 2）. 打印除重后的序列

// 9. 

// brute force - back tracking
int sumWeight = 0;
int sumValue = 0;
vector<int> value;
void packSack_BT(vector<int> weight, vector<int> value, int BAG) {
    if(sumWeight == BAG) {
        value.push_back(sumValue);
        return;
    }
    for(int i = 0; i < weight.size(); i++) {
        sumWeight += weight[i];
        sumValue += value[i];

    }
}

int min(vector<int> nums) {
    int res = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        res = min(res, nums[i]);
    }
    return res;
}

int LenOfRemoveDup(vector<int> nums) {
    if(nums.size() == 0) {
        return 0;
    }
    int res = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            res++;
        }
    }
    return res;
}

// TODO
int LenOfRmDup() {
    dp[];

    for(int i = 0; i < size; i++) {

    }
}

int LenOfIncreasingContigous(vector<int> nums) {
    vector<int> dp(nums.size() + 1, 0);
    int size = nums.size();
    dp[0] = 1;

    for(int i = 1; i < size; i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] += 1;
        } else {
            dp[i] = 0;
        }
    }
    return dp[size - 1];
}

int LenIncrea(vector<int> nums) {
    int size = nums.size();
    vector<int> dp(size, 0);
    dp[0] = 1;

    for(int i = 1; i < size; i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] += 1;
        } else {
            dp[i] = dp[i - 1];            
        }
    }
    return dp[size - 1];
}








// dp
int packSackLimit(const vector<int> weight, const vector<int> value, const int BAG) {
    int size = weight.size();
    vector<int> dp(BAG + 1, 0);

    for(int i = 0; i < size; i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

// 1. 完全背包: 容量为BAG的背包，从n个物品中任意选取，(weight[], value[]). 求装满背包的物品，最大的价值是多少？
int packsackNoLimit(const vector<int> weight, const vector<int> value, const int BAG) {
    int size = weight.size();
    vector<int> dp(BAG + 1, 0);

    for(int i = 0; i < size; i++) {
        for(int j = weight[0]; j <= BAG; j++) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

int main(void) {
    // string s = "abcdefghikl";
    // s = reverseStr2(s, 3);
    // cout << s << endl;
    // cout << isHappy(1810) << endl;

    string s = "ababab";
    string sub = "ab";
    // cout << isRepeat(s, sub) << endl;
    cout << test(s) << endl;

    return 0;
}