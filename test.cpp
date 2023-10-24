#include "test.hpp"


// TODO
int dp_24(int n) {
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {

        }
    }
    dp[j] = min(dp[j], dp[j - coins[i] * coins[i]] + 1);
}

// TODO
int dp_48() {

}

// TODO
// 给定一个字符串，计算这个字符串中有多少个回文子串
int dp_52() {
    int res = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i + 1; j < s.size(); j++) {
            if(s[i] == s[j]) {
                if(j - 1 <= 1) {
                    res++;
                    dp[i][j] = true;
                } else if(dp[i + 1][j - 1] == true) {
                    res++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return res;
}

// TODO
// 最长回文子序列: "bbbab" -> "bbbb"  4
int dp_53() {
    for(int i = 0; i < s.size(); i++) dp[i][i] = 1;

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i + 1; j < s.size(); j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.size() - 1];
}