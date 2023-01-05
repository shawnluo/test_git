#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

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