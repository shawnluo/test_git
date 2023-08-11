#include "test.hpp"

// using namespace std;

int main() {
    // vector<string> s = {"abc", "123"};
    // string su;
    // su.push_back(s[0][0]);
    // su.push_back(s[1][0]);

    // cout << su << endl;
 
    string s = "abc";

    //1. 
    string s1(s); 
    reverse(s1.begin(), s1.end());

    //2. 
    string s2;
    for(auto x : s) {
        s2.insert(0, 1, x);
    }
    cout << s2 << endl;

    return 0;
}