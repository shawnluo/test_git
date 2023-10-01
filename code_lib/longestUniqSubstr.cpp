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

int main(void) {
    string s = "abcada";
    cout << longest_u(s) << endl;

    return 0;
}