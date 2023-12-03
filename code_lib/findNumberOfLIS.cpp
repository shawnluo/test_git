

/*
    cnt数组是记录了以 i 这个元素结尾有多少条路径。然后我们还需要关心这个是怎么计算出来的。在计算dp数组的时候同时计算cnt，计算dp有两种情况：


    因为nums[i] > nums[j]，表示 i 可以接在 j 后面，

    一种是dp[j] + 1 > dp[i]，需要更新dp[i]的值；有一条从 j 到 i 的路径了，因为只有一条，所有cnt[i] = cnt[j]
    另外一种是dp[j] + 1 = dp[i]，表示前面已经更新了路径，因为cnt即记录有多少条路径到达，那就需要累计cnt了
*/
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();   // 数组长度
        vector<int> dp(n, 0);  // dp数组
        vector<int> cnt(n, 0); // 累计数组
        int max = 1;           // 最短的最长上升子序列为本身，长度为1
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i]  = 1; // 初始化
            cnt[i] = 1; // 初始化
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) { // i元素可以接在j元素后面
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1; // 更新dp
                        cnt[i] = cnt[j]; // 有一条从 j 到 i 的路径了，因为只有一条，所有cnt[i] = cnt[j]
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j]; // 累计所有的路径
                    }
                }
            }
            if (dp[i] > max) { // 最长长度变化，更新状态
                max = dp[i];
                ans = cnt[i];
            } else if (dp[i] == max) { // 最长长度不变，累计结果
                ans += cnt[i];
            }
        }
        return ans;
    }
};
