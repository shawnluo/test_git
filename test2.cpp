#include "test.hpp"



void permutation(string s, int pos) {
    int len = s.size();
    if(pos >= len) {
        cout << s << endl;
    }
    for(auto i = pos; i < len; i++) {
        swap(s[i], s[pos]);
        permutation(s, pos + 1);
        swap(s[i], s[pos]);
    }
}

void backtracking(int n, int k, int startIndex) {
    if(path.size() == k) {
        result.push_back(path);
        return;
    }
    for(auto i = startIndex; i <= n i++) {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}

void backTracking(int n, int k, int startIndex) {
    if(path.size() == k) {
        result.push_back(path);
        return;
    }
    for(auto i = startIndex; i <= n; i++) {
        path.push_back(i);
        backTracking(n, k, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    result.clear();

    vector<int> path;
    path.clear();

    backtracking(n, k, 1);

    return result;
}