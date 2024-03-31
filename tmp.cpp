
#include "test.hpp"

// "aabaabaafa" 0, 1
// "aaaba" 0, 1

void getNext(string& t, int* next) {
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < t.size(); i++) {
        while(j > 0 && t[i] != t[j]) {
            j = next[j - 1];
        }
        if(t[i] == t[j]) {
            j++;
        }
        next[i] = j;
    }
}

int mystrstr(string& s, string& t) {
    int n = t.size();
    int next[n];
    getNext(t, next);

    // for(int i = 0; i < n; i++) {
    //     cout << next[i] << " ";
    // }
    // cout << endl;

    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != t[j]) {
            j = next[j - 1];
        }
        if(s[i] == t[j]) {
            j++;
        }
        if(j == t.size()) {
            return i - t.size() + 1;
        }
    }

    return -1;
}

int main(void) {
    string s = "abcde";
    string t = "bc";
    int res = mystrstr(s, t);
    cout << res << endl;

    return 0;
}