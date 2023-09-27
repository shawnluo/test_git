// dp 52
// 回文子串:
// from the last char, back to first one.
// dp[i][j]: 从[i, j], 多少个回文子串
int dp_52(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for(int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
    }
    int res = 0;

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i; j < s.size(); j++) {
            if(s[i] == s[j]) {
                if(j - i <= 1) {
                    res++;
                    dp[i][j] = true;
                } else if(dp[i + 1][j - 1] == true) {
                    res++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp[0][s.size() - 1];
}