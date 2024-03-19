#include "test.hpp"

vector<char> sortByFreq2(vector<char>& v) {
    int freq[26] = {0};
    for(auto it : v) {
        freq[it - 'a']++;
        // cout << it - 'a' << endl;
    }

    // max heap to store frequencies
    priority_queue<int> pq;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            pq.push(freq[i]);
        }
    }
    
    // cout << pq.size() << endl;
    vector<char> res;
    
    while(!pq.empty()) {
        cout << pq.top() << endl;
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int main(void) {
    vector<char> v{'b', 'b', 'a', 'a', 'a', 'c'};
    vector<char> res = sortByFreq2(v);

    for(auto it : res) {
        // cout << it << " ";
    }
    cout << endl;
    
    return 0; 
}