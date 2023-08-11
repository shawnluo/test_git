#include "test.hpp"

// wrong solution
// case: aabcxcbaa 
string longestPalindrome_wrong(string s) {
    string s2(s);
    reverse(s2.begin(), s2.end());
    cout << s2 << endl;
    int maxI = 0;

    int max = 0;
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= s.size(); j++) {
            if(s[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(max < dp[i][j]) {
                    max = dp[i][j];
                    maxI = i - 1;
                    // maxJ = j - 1;
                }
            }
        }
    }
    string res;
    if(max == 0) return {};
    else {
        for(int i = 0; i < max; i++)
            res.push_back(s[maxI - i]);
    }
    return res;
}

string longestPalindrome(string s) {
    int len = s.size();
    if(len == 0) return "";

    int maxL = 0;
    int maxR = 0;
    vector<vector<int>> dp(len, vector<int>(len, 0));

    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;   // 任何一个单独的成员，都是回文，其dp都是1
    }

    for(int right = 1; right < len; right++) {
        for(int left = 0; left < right; left++) {
            if(s[left] == s[right] && (right - left == 1 || dp[left + 1][right - 1])) {
                dp[left][right] = 1;
                if(right - left > maxR - maxL) {
                    maxR = right;
                    maxL = left;
                }
            }
        }
    }
    return s.substr(maxL, maxR - maxL + 1);
}


int main(void){
    string s = "xabay";
    cout << longestPalindrome(s) << endl;

    return 0;
}