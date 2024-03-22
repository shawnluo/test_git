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

vector<vector<int>> insInterval(vector<vector<int>>& v, vector<int>& newV) {
    vector<vector<int>> res;
    int n = v.size();
    int i = 0;

    // 1. copy items before overlapping
    while(i < n && newV[0] > v[i][1]) {
        res.push_back(v[i++]);
    }

    // 2. merge
    while(i < n && newV[1] >= v[i][0]) {
        newV[0] = min(newV[0], v[i][0]);
        newV[1] = max(newV[1], v[i][1]);
        i++;
    }
    vector<int> pair = {newV[0], newV[1]};
    res.push_back(pair);

    // 3. copy items after overlapping
    while(i < n && newV[1] < v[i][0]) {
        res.push_back(v[i++]);
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

void test(volatile size_t* addr, size_t data, int len, size_t offset) {
    size_t left = (1 << (len + offset)) - 1;
    size_t right = (1 << (offset)) - 1;
    size_t mask = left - right;

    data <<= offset;
    data |= ~mask;

    *addr |= data;
}