#include "test.hpp"

// abccefa
int longestUniqSub(string s) {
    int hash[256];
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    int pos = -1;
    int len = 0;
    int res = -1;
    for(int i = 0; i < s.size(); i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}

int main(void) {
    string s = "abc";

    cout << longestUniqSub(s) << endl;
    return 0;
}