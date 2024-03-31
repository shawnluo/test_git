
// implement strstr: if sub is substring of s

// 1. brute force
bool isSubstr_bf(string s, string sub) {
    // loop from start to end in s1
    // loop from start to end in s2

    for(int i = 0; i < s.size(); i++) {
        int k = i;
        for(int j = 0; j < sub.size(); j++) {
            if(k < s.size() && s[k] != sub[j]) {
                break;
            }
        }
        if(j == sub.size()) {
            return true;
        }
    }
    return false;
}

// 2. dp
bool isSubstr_dp(string s, string sub) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(sub.size() + 1, 0));

    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= sub.size(); j++) {
            if(s[i - 1] == sub[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res == sub.size() ? true : false;
}

// 3. kmp
void getNext(int *next, string s) {
    next[0] = 0;
    int j = 0;

    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];   // j 找上一个匹配过得段落的下一个元素
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}


// return the start position of sub in s
int isSubstr_kmp(string s, string sub) {
    int next[sub.size()];
    getNext(next, sub);
    int j = 0;

    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != sub[j]) {
            j = next[j - 1];
        }
        if(s[i] == sub[j]) {
            j++;
        }

        if(j == sub.size()) {
            // return true;
            return i - sub.size() + 1;
        }
    }
    return -1;
}
