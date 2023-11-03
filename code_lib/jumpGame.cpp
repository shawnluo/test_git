

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