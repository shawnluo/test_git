

/*
这道题说的是有一个非负整数的数组，每个数字表示在当前位置的最大跳力（这里的跳力指的是在当前位置为基础上能到达的最远位置），
求判断能不能到达最后一个位置，
开始博主以为是必须刚好到达最后一个位置，超过了不算，其实是理解题意有误，
因为每个位置上的数字表示的是最大的跳力而不是像玩大富翁一样摇骰子摇出几一定要走几。
这里可以用动态规划 Dynamic Programming 来解，维护一个一维数组 dp，
其中 dp[i] 表示达到i位置时剩余的跳力，若到达某个位置时跳力为负了，说明无法到达该位置。
接下来难点就是推导状态转移方程啦，想想啊，到达当前位置的剩余跳力跟什么有关呢，
其实是跟上一个位置的剩余跳力（dp 值）和上一个位置新的跳力（nums 数组中的值）有关，
这里新的跳力就是原数组中每个位置的数字，因为其代表了以当前位置为起点能到达的最远位置。
所以当前位置的剩余跳力（dp 值）和当前位置新的跳力中的较大那个数决定了当前能到的最远距离，
而下一个位置的剩余跳力（dp 值）就等于当前的这个较大值减去1，因为需要花一个跳力到达下一个位置，
所以就有状态转移方程了：dp[i] = max(dp[i - 1], nums[i - 1]) - 1，
如果当某一个时刻 dp 数组的值为负了，说明无法抵达当前位置，则直接返回 false，最后循环结束后直接返回 true  即可，参见代码如下：


*/
bool canJump(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size, 0);

    for(int i = 1; i < size; i++) {
        dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
        if(dp[i] < 0) {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return true;
        int count = 0;
        for(int i = size - 2; i >= 0; i--) {
            if(nums[i] <= count) {
                count++;
            } else {
                count = 0;
            }
        }
        return count == 0;
    }
};

/*
其实这题最好的解法不是 DP，而是贪婪算法 Greedy Algorithm，
因为这里并不是很关心每一个位置上的剩余步数，而只希望知道能否到达末尾，
也就是说我们只对最远能到达的位置感兴趣，所以维护一个变量 reach，表示最远能到达的位置，初始化为0。
而所有小于等于 reach 的位置都可以通过连续跳跃到达的，则只要 reach 大于等于最后一位置，
就说明可以跳到最后一个位置。所以问题的核心就变成了尽可能的更新 reach 为最大值，
这样就可以一次遍历数组中的每个位置，若这个位置小于等于 reach，说明是在可以到达的范围内，
而从该位置可以到达的最大范围就是 i + nums[i]，用这个最大范围来更新 reach。
若某个时刻 reach 已经大于等于 n-1 了，说明可以到达最后的位置了，不需要进一步更新了，可以直接 break 掉循环。
循环退出了之后，比较 reach 和 n-1 的只，若大于等于则返回 true，否则返回 false，参见代码如下：
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};