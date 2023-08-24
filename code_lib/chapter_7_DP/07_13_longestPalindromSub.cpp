
/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

// 状态转移方程为：
//      dp[l][r] = (s[l] == s[r] && (r - l == 1 || dp[l + 1][r - 1])) ? true : false

class Solution {
public:
    string longestPalindrome(string s) {
        // 动态规划做
        int len = s.size();
        if (len == 0) return "";

        int max_l = 0, max_r = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i)
            dp[i][i] = 1;

        for (int right = 1; right < len; ++right) {
            for (int left = 0; left < right; ++left) {
                if (s[left] == s[right] && (right - left == 1 || dp[left + 1][right - 1])) {
                    dp[left][right] = 1;    // 从left 到 right是回文
                    if (right - left > max_r - max_l) {
                        max_r = right;
                        max_l = left;
                    }
                }
            }
        }
        return s.substr(max_l, max_r - max_l + 1);  //string a = s.substr(0, 5) 获得字符串s中从第0位开始的长度为5的字符串
    }
};

//TODO dp 方法二   
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();

        if (size < 2) return s;

        int maxLen = 1;
        int begin  = 0;
        vector<vector<int>> dp(size, vector<int>(size)); // i，j表示字符子串s(i到j)，故可以用二维数组表示
        for (int i = 0; i < size; ++i)                   // 所有长度为一的最长子串为true
            dp[i][i] = true;

        for (int subLen = 2; subLen <= size; ++subLen) // 子串长度遍历，这里要注意用==
        {
            for (int i = 0; i < size; ++i)             // 滑动窗口依次右滑
            {
                int j = i + subLen - 1;
                if (j >= size) // 滑动窗口右滑终止条件，反之越界
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else if (j - i < 3) // 此时只能为2，故为true
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];    // 状态转移方程代码实现

                if (dp[i][j] && j - i + 1 > maxLen) // 判断是回文，并且满足最大值才更新maxLen和begin
                {
                    maxLen = j - i + 1;             // 最大长度
                    begin  = i;                     // 起始位置
                }
            }
        }

        return s.substr(begin, maxLen); // 返回最长子串
    }
};

//TODO brute force
class Solution {
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string tmp(s);
        int size   = s.size();
        int subLen = size;
        for (; subLen > 0; --subLen) {
            for (int i = 0; i <= size - subLen; ++i) {
                tmp = s.substr(i, subLen);
                if (tmp == string(tmp.rbegin(), tmp.rend())) return tmp;
            }
        }
        return tmp;
    }
};