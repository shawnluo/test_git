#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100

//ladder climbing, one step or 2 steps once, how many ways to reach to the top
int ladder(int n) {
    int i, dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(i = 3; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("%d\n", dp[n]);
    return dp[n];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

static inline int min(int i, int j) {
    return i < j ? i : j;
}

int ladder_energy(int n, int cost[n]) {
    int i = 0;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = dp[0] + cost[0];

    for(i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    
    int cost[5] = {6, 4, 7, 2, 1};
    ladder_energy(5, cost);

    printf("%d\n", dp[n]);
    return 0;
}


//longest common subsequence
int lcs(char *s1, char *s2, int m, int n){
    int dp[MAX_LEN + 1][MAX_LEN + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char s1[MAX_LEN + 1] = "AGGTAB";
    char s2[MAX_LEN + 1] = "GXTXAYB";
    int m = strlen(s1);
    int n = strlen(s2);

    printf("Length of LCS is %d\n", lcs(s1, s2, m, n));

    return 0;
}