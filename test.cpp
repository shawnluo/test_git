#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

class comp {
public:
    bool operator()(const pair<int, int> lhs, const pair<int, int> rhs) {
        return lhs.second < rhs.second;
    }
};

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> map;
    for(auto it : nums) {
        map[it]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for(auto it = map.begin(); it != map.end(); it++) {
        pq.push(*it);
    }

    int res = 0;
    int val = pq.top().second;
    pq.pop();
    cout << val << endl;
    res += val;
    while(!pq.empty()) {
        int cur = pq.top().second;
        cout << cur << endl;
        // if(val != cur) {
            // return res;
        // }
        // res += val;
        pq.pop();
    }

    return res;
}

int main() {
    unordered_map<int, int> map;
    map.insert(make_pair(1, 100));
    map.insert(make_pair(2, 200));

    for(auto it = map.begin(); it != map.end(); it++) {
        cout << it->first << endl;
    }

    // auto it = map.find(100);
    // if(it != map.end()) {
    //     cout << 1 << endl;
    // }

    return 0;
}