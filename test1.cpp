
#include "test.hpp"

int hash_07(string ransom, string mag) {
    unordered_map<char, int> map;
    for(int i = 0; i < mag.size(); i++) {
        map[mag[i]]++;
    }
    for(int i = 0; i < ransom.size(); i++) {
        if(--map[ransom[i]] < 0) {
            return false;
        }
    }
    return true;
}

void demo_multiset() {
    std::unordered_multiset<string> set;
    set.insert("Shawn");
    set.insert("Julie");
    set.insert("Shawn");

    for(auto it : set) {
        cout << it << " ";
    }
    cout << endl;
}

void printQue(std::deque<int> que) {
    for(auto it : que) {
        cout << it << " ";
    }
    cout << endl;
}

int test() {
    std::deque<int> que;

    que.push_back(10);
    que.push_back(100);
    printQue(que);

    // que.pop_front();
    que.pop_back();
    printQue(que);

    return 0;
}


int main() {
    // string a = "axabx";
    // string b = "abax";
    // cout << hash_07(a, b) << endl;

    test();

    return 0;
}