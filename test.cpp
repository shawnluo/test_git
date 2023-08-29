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



// sum[left] + sum[right] = nums.size();
// sum[left] - sum[right] = S
// sum[left] = (nums.size() + S) / 2
// solution: 
// 01 背包：choose from nums[n], find the ways to total value: (nums.size() + S) / 2
int findTargetSumWays(vector<int> nums, int S) {
    int sum = 0;
    for(auto x : nums) {
        sum += x;
    }
    if(abs(S) > sum) {
        return 0;
    }
    if ((nums.size() + S) % 2) {
        return 0;
    };
    int BAG = (nums.size() + S) / 2;
    vector<int> dp(BAG + 1, 0);         // dp[j] - 凑成j的方法数

    for(int i = 0; i < nums.size(); i++) {
        for(int j = BAG; j >= nums[i]; j++) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[BAG];
}

#if 0
// TODO backtracking findTargetSumWays
int count = 0;
vector<int> buf;
vector<int> res;
int sum = 0;
void BackTracking(vector<int> nums, int S, int pos) {
    if(sum == S) {
        count++;
        return;
    }
    for(int i = ) {

    }
}
#endif

// backtracking basic
// 1. "abc" - 组合: abc acb bac bca cab cba
void backtracing(string s, int pos) {
    if(pos == s.size()) {
        cout << s << endl;
        return;
    }
    for(int i = pos; i < s.size(); i++) {
        swap(s[i], s[pos]);
        backtracing(s, pos + 1);
        swap(s[i], s[pos]);
    }
}

// TODO 17. 一和零
// 一个二进制字符串数组strs和两个整数m和n
// 找出并返回strs的最大子集的大小

// 19. 零钱兑换II
int change(vector<int> coins, int sum) {
    
}



int main(void) {
    vector<int> nums{1, 2, 3, 3, 4, 5, 5, 6};
    string s = "abc";
    backtracing(s, 0);
    // cout << getLen4(nums) << endl;

    return 0;
}