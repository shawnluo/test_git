


#include "test.hpp"
#include <thread>

using namespace std;

<<<<<<< Updated upstream



// the first pos
int dp_48(string& s, string& t) {
    int sLen = s.size();
    int tLen = t.size();
    vector<vector<int>> dp(sLen + 1, vector<int>(tLen + 1, 0));

    for(int i = 0; i <= sLen; i++)   dp[i][0] = 1;
    for(int j = 1; j <= tLen; j++)   dp[0][j] = 0;

    for(int i = 1; i <= sLen; i++) {
        for(int j = 1; j <= tLen; j++) {
=======
// 012345 -> 2345 01
// 543210 -> 2345 01

// the number of distinct subsequences of s which quals t
int numDistinct(string& s, string& t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    // dp[i][j]: end with i - 1 in s, the number of end with j - 1
    int n = s.size();

    for(int i = 0; i < s.size(); i++) {
        dp[i][0] = 1;
    }

    for()

    for(int i = 1; i < s.size(); i++) {
        for(int j = 1; j < t.size(); j++) {
>>>>>>> Stashed changes
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
<<<<<<< Updated upstream
            }
        }
    }
    return dp[sLen][tLen];
}

int dp_49(string& s, string& t) {
    int sLen = s.size();
    int tLen = t.size();

    vector<vector<int>> dp(sLen + 1, vector<int>(tLen + 1, 0));
    
    for(int i = 0; i <= sLen; i++)  dp[i][0] = i;
    for(int j = 0; j <= tLen; j++)  dp[0][j] = j;

    for(int i = 1; i <= sLen; i++) {
        for(int j = 1; j <= tLen; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
    }
    return dp[sLen][tLen];
}

int main(void) {
    string s = "rabbbit";
    string t = "ab";
    cout << dp_49(s, t) << endl;
=======
            }
        }
    }
    return dp[s.size()][t.size()];
}


int main(void) {
    string s = "babgbag";
    string t = "bag";
    int ret = numDistinct(s, t);
    cout << ret << endl;
>>>>>>> Stashed changes

    return 0;
}

show me the money