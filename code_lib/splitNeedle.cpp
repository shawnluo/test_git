
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

vector<string> myStrtok_1(char* hay, const char needle) {
    string s;
    vector<string> res;

    for(int i = 0; hay[i] != '\0'; i++) {
        if(hay[i] != needle) {
            s.push_back(hay[i]);
        } else {
            res.push_back(s);
            s.clear();
        }
    }
    res.push_back(s);

    return res;
}

int main() {
    char* hay = "show me the moeny!";
    const char needle = ' ';

    vector<string> res = myStrtok_1(hay, needle);
    for(auto it : res) {
        cout << it << endl;
    }

    return 0;
}