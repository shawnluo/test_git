#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


static inline int min(int i, int j) {
    return i < j ? i : j;
}

int ladder_energy(int n, int cost[n]) {
    int i = 0;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;

    for(i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    printf("%d\n", dp[n]);
    return 0;
}

int main(void) {
    int cost[5] = {6, 4, 7, 2, 1};
    ladder_energy(5, cost);

    return 0;
}