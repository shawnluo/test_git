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

int main(void) {
    // string s = "abcdefghikl";
    // s = reverseStr2(s, 3);
    // cout << s << endl;
    cout << isHappy(1810) << endl;
    return 0;
}