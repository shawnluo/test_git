
#include "test.hpp"

void test_CompletePack() {
    vector<int>weight = {1, 3, 4};
    vector<int>value = {15, 59, 25};
    int bagWeight = 4;
    vector<int>dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
         // 遍历物品
        // for(int j = weight[i]; j <= bagWeight; j++) {
        for(int j = 0; j <= bagWeight; j++) {
            // 遍历背包容量
            if(j >= weight[i])
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout<<dp[bagWeight] <<endl;
}

int main() {
    test_CompletePack();
    return 0;
}