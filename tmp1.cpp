#include "test.hpp"



void test(vector<int>& v) {
    v.erase(v.begin() + 0);
}

int main() {
    string s = "abc";
    cout << s.size() << endl;
    s.erase(0, 1);
    cout << s << endl;
    cout << s.size() << endl;

    return 0;
}