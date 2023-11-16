
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

#include <iostream>
#include <string>


int dp() {
    for(int i = 0; i < weight.size(); i++) {
        for(int j = weight[i]; j <= BAG; j++) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
}

for() {
    for() {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    }
}

int main() {


    return 0;
}