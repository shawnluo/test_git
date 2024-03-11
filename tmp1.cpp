#include "test.hpp"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

// string s;
// vector<string> res;

void dfs(vector<string>& res, string cur, int left, int right, int n) {
    if(cur.size() == n * 2) res.push_back(cur);
    if(left < n) {
        dfs(res, cur + 'C', left + 1, right, n);
    }
    if(right < n) {
        dfs(res, cur + ')', left, right + 1, n);
    }
}


int main() {
    
    dfs();

    return 0;
}