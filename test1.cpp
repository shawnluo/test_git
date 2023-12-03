
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

#include <iostream>
#include <string>

vector<pair<string, int>> v = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, \
                {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};


// IV - 4
// CI - 101
int romanToInt(string s) {
    int pair[256];
    pair['I'] = 1;
    pair['V'] = 5;
    pair['X'] = 10;
    pair['L'] = 50;
    pair['C'] = 100;
    pair['D'] = 500;
    pair['M'] = 1000;

    int n = s.size();
    int res = 0;
    // for(auto it = s.begin(); it != s.end(); it++) {
    for(int i = 0; i < n; i++) {
        if(s[i] < s[i + 1]) {
            res -= pair[s[i]];
        } else {
            res += pair[s[i]];
        }
    }
    return res;
}

int main() {
    cout << romanToInt("IV") << endl;

    return 0;
}