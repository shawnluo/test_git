
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

int dp_19(vector<int> coins, int sum) {
    vector<int> dp(sum + 1, 0);

    for(int i = 0; i < coins.size(); i++) {
        for(int j = 0; j <= sum; j++) {
            if(j >= coins[i])
                dp[j] += dp[j - coins[i]];
        }
    }
}

for(int i = 0; i <= BAG; i++) {
    for(int j = 0; j < n; j++) {
        dp[i] += dp[i - nums[i]];
    }
}

dp[0] = 1;
for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
        dp[i] += dp[i - j];
    }
}


// vector<int> coins;
// int BAG;
// minimal coins

vector<int> dp(BAG + 1, INT_MAX);
// dp[i] choose from [0, i], the minimal amount of coins.
dp[0] = 0;
for(int i = 0; i < n; i++) {
    for(int j = 0; j <= BAG; j++) {
        dp[j] = min(dp[j], dp[i - coins[i]] + 1);
    }
}

for(int i = 1; i * i <= n; i++) {
    for(int j = i * i; j <= n; j++) {
        dp[j] = min(dp[j], dp[j - i * i] + 1);
    }
}

dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

dp[i][0] = max(-price[i], dp[i - 1][0]); //是一个负值
dp[i][1] = max(dp[i][0] + price[i], dp[i - 1][1]);

int main(void) {

    return 0;
}