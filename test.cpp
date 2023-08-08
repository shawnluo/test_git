#include "test.hpp"

#include <stdio.h>

// remove duplicated element from a array


int rmDup(int *arr, int len) {
    int dp[len] = {0};
    dp[0] = 1;
    for(int i = 1; i < len; i++) {
        if(arr[i] != arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[len - 1];
}

int main(void) {
    int arr[5] = {1, 2, 2, 3, 4};
    printf("%d\n", rmDup(arr, 5));

    return 0;
}