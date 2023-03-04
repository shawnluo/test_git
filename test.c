#include "common.h"
#include "test.h"

int max(int x, int y) {
    return x > y ? x : y;
}

int longest_increase_arr(int *arr, int len) {
    int dp[len];

    int res = 0;
    for(int i = 0; i < len; i++) dp[i] = 1;

    for(int i = 1; i < len; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(dp[i], res);
    }
    printf("%d\n", res);
    return res;
}

int maxSubArray(int *arr, int len) {
    int dp[len];
    int res = INT_MIN;
    dp[0] = arr[0];

    for(int i = 1; i < len; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
    return res;
}

int main(void) {
    int arr[] = {1, 7, -9, 0, 12};
    int len = sizeof(arr) / sizeof(arr[0]);
    longest_increase_arr(arr, len);
    //maxSubArray(arr, len);

    return 0;
}