

int intBreak(int num) {
    vector<int> dp(num + 1);
    dp[2] = 1;

    for(int i = 3; i <= num; i++) {
        for(int j = 1; j < i; j++) {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }
    return dp[num];
}