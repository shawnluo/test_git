#include "common.h"
#include "test.h"


int fib(int n) {
    //dp i = dp i - 1 + dp - 2
    int dp[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}


//TODO
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


int main(void) {
    //char s[] = "abc";
    //find_anagrams("xvabc", "av");
    
    return 0;
}