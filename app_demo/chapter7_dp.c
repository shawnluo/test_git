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

int ladder_cost(int n, int cost[n]) {
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


//longest common subsequence
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

int robot(int m, int n) {
    int dp[m][n];
    for(int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for(int j = 0; j < m; j++) {
        dp[0][j] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int robot_obstacals(int m, int n, int obstacle[m][n]) {
    int dp[m][n];
    int i, j;
    for(i = 0; i < m && obstacle[i][0] == 0; i++) {
        dp[i][0] = 1;
    }
    for(j = 0; j < n && obstacle[0][j] == 0; j++) {
        dp[0][j] = 1;
    }

    for(i = 1; i < m; i++) {
        for(j = 1; j < n; j++) {
            if(obstacle[i][j] == 1) {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}


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

int tribonacci(int n){
    //int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i < n; i++) {
        dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];
    }
    printf("%d\n", dp[n]);
    //return dp[n];
    return 1;
}

/*  Longest Increasing Subsequence
    2, 9, 3, 0, 5, 13 -> 2, 3, 5, 13

*/
int longest_increasing_subseq(int nums[], int len) {
    int dp[len];
    int res = INT_MIN;

    //dp[i]: longest sub sequence including nums[i]
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[i] > dp[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = dp[i] > res ? dp[i] : res;
    }
    return res;
}


void knapsack() {
    int knapsack = 100; //knapsack cap
    int weight[5] = {1, 76, 5, 18, 7};
    int value[5] = {10, 65, 91, 6, 18};
    int size = sizeof(weight) / sizeof(weight[0]);
    int dp[size][size + 1];
    int i, j;

    for(j = weight[0]; j <= knapsack; j++) {
        dp[0][j] = value[0];
    }

    for(i = 1; i < size; i++) {
        for(j = 0; j <= knapsack; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    printf("%d\n", dp[size - 1][size]);
}


int main() {
    char s1[MAX_LEN + 1] = "AGGTAB";
    char s2[MAX_LEN + 1] = "GXTXAYB";
    int m = strlen(s1);
    int n = strlen(s2);

    printf("Length of LCS is %d\n", lcs(s1, s2, m, n));

    return 0;
}