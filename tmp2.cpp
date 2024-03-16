#include "test.hpp"

int main() {
    auto exists = [](unordered_set<char>& s, int val) {
        return s.insert(val).second;
    };

    vector<unordered_set<char>> row(5);
    row[0].insert('a');
    row[0].insert('b');
    row[0].insert('c');

    // cout << exists(row[0], 'f') << endl;
    exists(row[0], 'a');
    for(auto it = row[0].begin(); it != row[0].end(); it++) {
        cout << *it << endl;
    }

    return 0;
}