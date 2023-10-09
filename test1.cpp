
#include "test.hpp"



int longest(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));

    for(auto x : dp) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

int main() {
    string s = "abac";
    cout << longest(s) << endl;
    return 0;
}
