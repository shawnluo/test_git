


#include "test.hpp"
#include <thread>

using namespace std;




// the first pos
int dp_48(string& s, string& t) {
    int sLen = s.size();
    int tLen = t.size();
    vector<vector<int>> dp(sLen + 1, vector<int>(tLen + 1, 0));

    for(int i = 0; i <= sLen; i++)   dp[i][0] = 1;
    for(int j = 1; j <= tLen; j++)   dp[0][j] = 0;

    for(int i = 1; i <= sLen; i++) {
        for(int j = 1; j <= tLen; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
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

    return 0;
}