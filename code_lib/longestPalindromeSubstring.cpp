#include "test.hpp"

int longestPalindromeSubstring(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for(int i = 0; i < s.size(); i++) {
        // dp[i][i] = true;
    }
    int res = 0;

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i; j < s.size(); j++) {
            if(s[i] == s[j]) {
                if (j - i <= 1) {
                    res = max(res, j - i + 1);
                    dp[i][j] = true;
                } else if (dp[i + 1][j - 1] == true) {
                    res = max(res, j - i + 1);
                    dp[i][j] = true;
                }
            }
        }
    }
    return res;
}

int main() {
    string s = "abcxbac";
    cout << dp_52(s) << endl;

    return 0;
}
