// dp 47
bool dp_47(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[s.size()][t.size()] == t.size() ? true : false;
}
