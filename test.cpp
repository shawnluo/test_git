#include "test.hpp"



typedef struct BTree {
    int val;
    BTree* left;
    BTree* right;

    BTree(int data) : val(data), left(nullptr), right(nullptr) {}
} bTree;

typedef struct Node {
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {}
} node, *pNode;

void reverse(string& s, int start, int end) {
    for(int i = start, j = end; i < j; i++, j--) {
        std::swap(s[i], s[j]);
    }
}

string reverseStr2(string s, int k) {
    int size = s.size();
    int index = 0;
    while(index < size) {
        if((size - index) < k) {
            reverse(s, index, size - 1);
            break;
        } else if((size - index) < 2 * k) {
            reverse(s, index, index + k - 1);
            break;
        } else {
            reverse(s, index, index + k - 1);
            index += 2 * k;
        }
    }
    return s;
}

string replaceSpaces(string s) {
    int count = 0;
    return {};
}

int getSum(int n) {
    int sum = 0;
    while(n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> set;

    while(1) {
        int sum = getSum(n);
        if(sum == 1) {
            return true;
        }
        if(set.find(sum) != set.end()) {
            return false;
        } else {
            set.insert(sum);
        }
        n = sum;
    }
}

// ===========
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

int s53_longestPalindromeSubseq(string s) {
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

void rmExtraSpaces(string& s) {
    int size = s.size();
    int index = 0;
    int fastIndex = 0;
    int slowIndex = 0;

    while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
        fastIndex++;
    }

    while(fastIndex < size) {
        if(fastIndex - 1 > 0 && \
                s[fastIndex - 1] == ' ' && \
                s[fastIndex] == ' ') {
            fastIndex++;
        } else {
            s[slowIndex] = s[fastIndex];
            fastIndex++, slowIndex++;
        }
    }
    if(slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
        s.resize(slowIndex - 1);
    } else {
        s.resize(slowIndex);
    }
}

string reverseWords(string s) {
    rmExtraSpaces(s);
    reverse(s, 0, s.size() - 1);
    int size = s.size();
    int start = 0;
    int i;
    while(i < size) {
        
    }
}

bool isRepeat(string s, string sub) {
    int j = 0;
    if(s.size() % sub.size()) {
        return false;
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != sub[j]) {
            return false;
        }
        if(++j == sub.size()) {
            j = 0;
        }
    }
    return true;
}

bool test(string s) {
    int size = s.size();

    for(int i = 1; i < size; i++) {
        string sub = s.substr(0, i);
        if(isRepeat(s, sub) == true) {
            return true;
        }
    }
    return false;
}

bool isHappy() {
    // in while(1) loop
        // 1. cal the sum function
        // 2. if the sum equal 1, then return true;
        // 3. check if this sum is in the unordered_set
        //      3.1. if yes, then return fasle
        //      3.2. if no, then put the sum into norodered_set
}

void getNext(const string s, vector<int>& next) {
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int myStrstr(const string s, const string needle) {
    vector<int> next(needle.size());
    getNext(s, next);
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != needle[j]) {
            j = next[j - 1];
        }
        if(s[i] == needle[j]) {
            j++;
        }
        if(j == needle.size()) {
            return i - needle.size() + 1;
        }
    }
    return -1;
}

int maxProfit(const vector<int> prices) {
    int res = 0;
    int size = prices.size();

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            res = max(res, prices[j] - prices[i]);
        }
    }
    return res;
}

int maxProfit2(const vector<int> prices) {
    int res = 0;
    int size = prices.size();

    // 1. day i - maxprofit - have stock
    // dp[i][0] = 

    // 2. day i - maxprofit - do NOT have stock
    // dp[i][1]

}

int change(vector<int> coins, int amount) {
    int size = coins.size();
    vector<int> dp(size, 0);

    // dp[i]: 
}

int bag() {
    for(int i = 0; i < size; i++) {
        for(int j = bag; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
}


int coin(vector<int> coins, int amount) {
    int size = coins.size();
    vector<int> dp(size, INT_MAX); // dp[j]: the minimum amount coins to fullfile amount

    // 凑足总额为 j - coins[i] 的最小个数 - dp[j - coins[i]]
    // 凑足总额为 j            的最小个数 - dp[j - coins[i]] + 1
    // dp[j] = min(dp[j], dp[j - coins[i]] + 1)
    
    dp[0] = 0;

    for(int i = 0; i < size; i++) {
        for(int j = coins[i]; j < amount; j++) {
            if(dp[j - coins[i]] != INT_MAX) {   // dp[j - coins[i]]: 不取 coins[i] 这个硬币，所需最小硬币数 - 初始化为INT_MAX
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
}

// 1. 装满背包的最大价值是多少？    - 纯完全背包
// 2. 装满背包有多少种方法？求组合  - 零钱兑换2
// 3. 装满背包有多少种方法？求排列  - 组合总和4
// 4. 装满背包最少用多少个物品？    - 322零钱兑换

int main(void) {
    // string s = "abcdefghikl";
    // s = reverseStr2(s, 3);
    // cout << s << endl;
    // cout << isHappy(1810) << endl;

    string s = "ababab";
    string sub = "ab";
    // cout << isRepeat(s, sub) << endl;
    cout << test(s) << endl;

    return 0;
}