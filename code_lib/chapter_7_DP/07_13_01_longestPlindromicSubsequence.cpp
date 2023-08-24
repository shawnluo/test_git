/*
516. Longest Palindromic Subsequence
Medium
8.9K
312
company
Cisco
company
Amazon
company
Goldman Sachs
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }
    int size = s.size();
    for(int i = size - 1; i >= 0; i--) {
        for(int j = i + 1; j < size; j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][size - 1];
}