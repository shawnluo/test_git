
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


#include <iostream>
#include <string>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int minSteps(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int n1 = s.size();
    int n2 = t.size();

    vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));

    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << s << endl;
    cout << t << endl;

    int count = dp[n1][n2];
    cout << count << endl;
    
    count = n1 - count;

    cout << count << endl;

    return count;
}

void test(string& s) {
    dp[i]: from nums[0, i] the maximum sum
    dp[i] = max(dp[i - 1] + nums[i], nums[i])
    
}

int main() {
    string s = "leetcode";
    string t = "practice";
    // minSteps(s, t);
    test(s);

    return 0;
}