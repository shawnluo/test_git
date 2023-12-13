
#include "test.hpp"

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;


void getNext(string s, vector<int>& next) {
    int n = s.size();
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int myStrstr(string s, string sub) {
    int n = sub.size();
    vector<int> next(n, 0);
    getNext(sub, next);

    int j = 0;
    for(int i = 0; i < n; i++) {
        while(s[i] != sub[j] && j > 0) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        if(j == sub.size()) {
            return i - sub.size() +1;
        }
    }
    return -1;
}

int longestUniqStr(string s) {
    int n = s.size();
    int pos = -1;
    vector<int> hash(256, -1);
    int len = 0;
    int res = 0;

    for(int i = 0; i < n; i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}

bool isLittle() {
    int i = 1;
    char* c = (char*)&i;

    return *c == 1 ? true : false;
}