// dp 48
/*
    string s and string t, 求在s的子序列中，t出现的个数
    dp[i][j]: 以i - 1为结尾的s子序列中，出现以j - 1为结尾的个数
    if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
*/
int dp_48(string s, string t) {
    return 0;
}