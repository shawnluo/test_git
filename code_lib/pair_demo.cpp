#include "../test.hpp"
    
void test() {
    // 1. set pair
    set<pair<int, int>> sPair = {{-1, 0}};
    sPair.insert({0, 1});
    sPair.insert({0, 1});   // 自动去重
    bool res = sPair.count({0, 1});
    cout << res << endl;

    // 2. vector pair
    // vector<pair<int, int>> vPair = {{1, 1}};
    vector<pair<int, int>> vPair;
    // vPair.push_back({0, 1});

    // 3. convert: set -> vector
    vPair.assign(sPair.begin(), sPair.end());
    for(auto it : vPair) {
        cout << it.first << "\t" << it.second << endl;
    }

    // 4. convert: vector -> set
    vector<int> v = {1, 2, 3, 1};
    set<int> mySet(v.begin(), v.end()); // 自动去重
    for(auto it : mySet) {
        cout << it << "\t";
    }
    cout << endl;

}

int main() {
    test();
    return 0;
}
