
#include "test.hpp"

int leastInterval(vector<char>& tasks, int n) {
    int freq[26] = {0};
    for(char ch : tasks) {
        freq[ch - 'a']++;
        // cout << freq[ch - 'a'] << endl;
    }

    priority_queue<int> pq;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            pq.push(freq[i]);
        }
    }

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    // int time = 0;
    // while(!pq.empty()) {
    //     int cycle = n + 1;
    //     while(cycle-- && !pq.empty()) {
    //         if(pq.top() > 1) {
    //             store.push_back(pq.top() - 1);
    //         }
    //     }
    // }

    return 0;
}

vector<int> topKFreq(vector<char>& v, int k) {
    // unordered_map<int, int> umap = {
    //     {5, 50},
    //     {2, 20},
    //     {9, 90},
    //     {1, 10},
    //     {3, 30}
    // };

    unordered_map<char, int> umap;
    for(auto i = 0; i < v.size(); i++) {
        umap[v[i]]++;
    }

    // for(auto it : umap) {
        // cout << it.first << " " << it.second << endl;
    // }

    // vector<pair<int, int>> vec(umap.begin(), umap.end());
    // sort(vec.begin(), vec.end());
    // sort(vec.end(), vec.begin(), [](const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.second < b.second; // sort by the second element of the pair
    // });

    // for(const auto& it : vec) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // sort(umap.begin(), umap.end());

    // vector<pair<char, int>> mapV(umap.begin(), umap.end());
    // sort(mapV.begin(), mapV.end());

    // for(auto it : mapV) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // priority_queue<pair<char, int>> pq;
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    for(auto it : umap) {
        pq.push(it);
    }

    while(!pq.empty()) {
        // auto topPair = pq.top();
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return {};
}



int main() {
    // vector<char> tasks = {'a', 'b', 'c', 'a', 'a', 'b', 'c'};
    // leastInterval(tasks, 2);

    vector<char> nums{'x', 'b', 'a', 'c', 'b', 'a', 'z', 'x'};
    topKFreq(nums, 3);
    

    return 0;
}