
#include "test.hpp"

void permu(string s, int pos) {
    if(pos == s.size()) {
        cout << s << endl;
    }
    for(int i = pos; i < s.size(); i++) {
        swap(s[i], s[pos]);
        permu(s, i + 1);
        swap(s[i], s[pos]);
    }
}

void backTracking(int n, int k, int pos) {
    if(path.size() == k) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i <= n; i++) {
        path.push_back(i);
        backTracking(n, k, i + 1);
        path.pop_back();
    }
}

int dp_08(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], max((j - i) * i, dp[j - i] * i));
        }
    }
    return dp[n];
}

for(int i = 0; i < weight.size(); i++) {
    for(int j = BAG; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
return dp[BAG];

const string letterMap[10] = {
    "",
    "",
    "abc", // 2
    "def", // 3
    "ghi", // 4
};


// 234
vector<string> res;
string s;
void BT(const string& digits, int index) {
    if(index == digits.size()) {
        res.push_back(s);
        return;
    }

    int digit = digits[index] - '0';
    string letters = letterMap[digit];

    for(int i = 0; i < letters.size(); i++) {
        s.push_back(letters[i]);
        BT(digits, index + 1);
        s.pop_back();
    }
}

void BT(const string& digits, int index){
    if(index == digits.size()) {
        res.push_back(s);
        return;
    }
    int digit = digits[index] - '0';
    string letters = letterMap[digit];
    for(int i = 0; i < letters.size(); i++) {
        s.push_back(letters[i]);
        BT(digits, index + 1);
        s.pop_back();
    }
}

vector<string> BT_05(string digits) {
    s.clear();
    res.clear();
    BT(digits, 0);

    return res;
}


for()
    hash[i] = -1;

int pos = -1;
int len = 0;
int res = 0;
for(int i = 0; i < s.size(); i++) {
    pos = max(pos, hash[s[i]]);
    len = i - pos;
    res = max(res, len);
    hash[s[i]] = i;
}
return res;


int removeExtraSpaces(string s) {
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            if(j > 0) {
                s[j++] = ' ';
            }
            while(i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }
    }
    s.resize(j);
    return j;
}

int main(void) {
    string s = "abcd";
    permu(s, 0);

    return 0;
}