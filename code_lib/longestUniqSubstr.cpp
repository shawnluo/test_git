int longest_u(string s) {
    int hash[256];
    int len = 0;
    int pos = -1;
    int res = 0;
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    for(int i = 0; i < 256; i++) {
        // cout << hash[i] << " ";
    }
    
    for(int i = 0; i < s.size(); i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}

// 打印出来
int longestUniqString(string s) {
    int hash[256];
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    int size = s.size();
    int pos = -1;
    int len = 0;
    int res = 0;
    int lhs = 0;
    int rhs = 0;

    for(int i = 0; i < size; i++) {
        pos = max(pos, hash[s[i]]);
        lhs = pos + 1;
        len = i - pos;
        rhs = i;
        if(len > res) {
            lhs = pos + 1;
            res = len;
            rhs = i;
        }
        hash[s[i]] = i; // using hash[s[i]] to store and update the s[i] most recently postion.
    }

    cout << s.substr(lhs, rhs) << endl;
    
    return res;
}

int main(void) {
    string s = "abcada";
    cout << longest_u(s) << endl;

    return 0;
}