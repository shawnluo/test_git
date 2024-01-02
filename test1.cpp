
#include "test.hpp"

#include <semaphore.h>
#include <unistd.h>
using namespace std;


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

/*
    10 producers, 1 consumer
*/


/*信号量实现 多生产者 多消费者问题*/



int dp_11(vector<int> weight, vector<int> value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int>(BAG, 0));
    // dp[i][j]: 取物品[0, i], 背包容量为j，最大价值
    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][BAG] = value[0];
    }

    for(int i = 0; i < weight.size(); i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

}


int main() {

    return 0;
}