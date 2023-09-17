#include "test.hpp"

int main(void) {
    string s = "abcd";
    string sub = "cd";

    cout << s.substr(1, 3) << endl;

    return 0;
}