#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


int max(int x, int y) {
    return x > y ? x : y;
}

int integer_break(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    memset(dp, 0, sizeof(int) * (n + 1));

    int i, j;
    for(i = 3; i <= n; i++) {
        for(j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
        }
    }
    printf("%d\n", dp[n]);
    return dp[n];
}

int longest_common_subsequence(char *arr1, char *arr2) {
    int m = strlen(arr1);
    int n = strlen(arr2);
    int dp[m + 1][n + 1];
    int i, j;
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    
    return dp[m][n];
}


int main(void) {
    //int cost[5] = {6, 4, 7, 2, 1};
    //ladder_energy(5, cost);
    //integer_break(10);
    
    char arr1[] = "abcxd";
    char arr2[] = "xabcrpd";
    longest_common_subsequence(arr1, arr2);
    
    return 0;
}