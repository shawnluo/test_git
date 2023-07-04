#include "test.hpp"

class Solution {
public:
    int backpack() {
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagweight = 4;
        int size = weight.size();

        vector<int> dp(bagweight + 1, 0);

    // 在一维dp的时候要逆序是因为作者相对于二维没有了初始化的过程，

        for (int i = 1; i <= size; i ++) {
            if (weight[0] > i) {
                continue;
            }
            dp[i] = value[0];
        }

        // 添加这个初始化后，从第二个开始遍历就行，不需要逆序，这样代码基本和前面二维差不多
        for (int i = 1; i < size; i ++) {
            for (int j = 0; j <= bagweight; j ++) {
                if(j >= weight[i]) {
                    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
            }
        }
        return dp[size - 1];
    }
};

int main(void) {
    Solution solution;
    int res = solution.backpack();
    cout << res << endl;

    return 0;
}