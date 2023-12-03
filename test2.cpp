#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>


// C++ program to demonstrate
// multithreading using three
// different callables.
#include <iostream>
#include <thread>
using namespace std;


/* int main(void) {
    string s = "1234567890";
    set<string> Set;
    Set.insert(s.substr(0, 3));
    Set.insert(s.substr(3, 3));
    Set.insert(s.substr(6, 3));

    // for(auto it : Set) {
    //     cout << it << endl;
    // }

    cout << Set.front() << endl;

    return 0;
} */

string largestGoodInteger(string num) {
    int n = num.size();
    if(n < 3) return {};

    set<string> mySet;
    string res;
    for(int i = 2; i < n; i++) {
        if(num[i] == num[i - 1] && num[i] == num[i - 2]) {
            // cout << num.substr(i - 2, 3) << endl;
            mySet.insert(num.substr(i - 2, 3));
        }
    }
    if(mySet.size() != 0) {
        return *mySet.rbegin();
    }
    return {};
}

int main() {
    string s = "6777133339";

    cout << largestGoodInteger(s) << endl;

  return 0;
}