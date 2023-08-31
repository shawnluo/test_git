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

// 41.
int lengthOfLCS(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

// 42. 
int lengthOfLCIS(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        res = max(res, dp[i]);
    }
    return res;
}

// 43. 最长重复子数组
int lengOfLRS(vector<int> nums1, vector<int> nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int> (nums2.size() + 1, 0));
    int res = 0;
    // dp[i][j]: when nums1[0, i] and nums2[0, j], the longest repeat sub array
    for(int i = 1; i <= nums1.size(); i++) {
        for(int j = 1; j <= nums2.size(); j++) {
            if(nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

// 44. 最长公共子序列
int dp_44(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}


// 46. 最大子序和
// 最大连续子数组和
int dp_46(vector<int> nums) {
    if(nums.size() == 0) {
        return 0;
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int res = dp[0];

    for(int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i], dp[i - 1] + nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}

// 47. 判断是否子序列。注意，不是子串！
int dp_47(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s1.size()][s2.size()] == s2.size() ? true : false;
}

// 47.1 判断是否子串
int dp_47_1(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
    int res = 0;
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            res = max(res, dp[i][j]);
        }
    }

    return res == s2.size() ? true : false;
}

// int isSub(string s1, string s2) {
int isSub(const char *s1, char *s2) {
    for( ; *(s1 + strlen(s2) - 1) != '\0'; s1++) {
        if(strncmp(s1, s2, strlen(s2)) == 0) {
            return true;
        }
    }
    return false;
}

int isSubString(string s1, string s2) {
    for(int i = 0; i < s1.size() - s2.size() + 1; i++) {
        if(s1.substr(i, s2.size()) == s2) {
            return true;
        }
    }
    return false;
}

int main(void) {
    // vector<int> nums{1, 1, 2, 2, 2, 3, 4, 5, 5};
    // vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // cout << lengthOfLCS(nums) << endl;
    // cout << dp_46(nums) << endl;

    char s1[] = "abcde";
    char s2[] = "ade";
    cout << dp_47(s1, s2) << endl;

    return 0;
}
