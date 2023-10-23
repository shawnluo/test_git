
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

int main(void) {
    string s = "abcd";
    permu(s, 0);

    return 0;
}