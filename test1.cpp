
#include "test.hpp"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

// TODO 
// 1. meeting
// 2. memory alignment - memory copy
// 3. memory alignment - memory move
// 4. sortBy freq
// 5. calculator
// 6. longest uniq characters length

// 3 2 4 + *
void cal(vector<char>& s) {
    
}

// 3+2*4
void cal_noPri(string& s) {

}
void cal_priority(string& s) {

}

int longestUniqSub(string& s) {
    int n = s.size();
    int pos = -1;
    int len = 0;
    int res = 0;

    unordered_map<char, int> map;
    for(int i = 0; i < 256; i++) {
        map[i] = -1;
    }

    // for(auto it : map) {
    //     cout << it.second << endl;
    // }

    for(int i = 0; i < n; i++) {
        pos = max(pos, map[s[i]]);
        len = i - pos;
        res = max(res, len);
        map[s[i]] = i;
    }

    return res;
}

int main(void) {
    string s = "1123341516";
    int res = longestUniqSub(s);
    cout << res;

    return 0;
}