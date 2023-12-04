
#include "test.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    s.insert(0, "x");
    // cout << s << endl;
    char* t = "yy";
    string x(t);
    s.insert(0, x);
    cout << s << endl;

    return 0;
}