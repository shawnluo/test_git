// dp 49
/*
    两个字符串的删除操作：找到使得s和t相同，所需的最小步数。每步可以删除任意一个字符串
    dp[i][j]: 以i - 1为结尾的s，和以j - 1为结尾的t, 想要达到相等，所需要删除元素的最少次数
*/
int dp_49(string s1, string s2) {
    vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 0; i <= s1.size(); i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= s2.size(); j++) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
    }

    return dp[s1.size()][s2.size()];
}