#include "test.hpp"

vector<char> sortByFreq2(vector<char>& v) {
    map<char, int> umap;
    for(auto it : v) {
        umap[it]++;
    }

    for(auto it : umap) {
        cout << it.second << endl;
    }

    /* vector<pair<char, int>> mapV(umap.begin(), umap.end());

    sort(mapV.begin(), mapV.end());
    for(auto it : mapV) {
        cout << it.second << endl;
    }

    sort(mapV.begin(), mapV.end(),
        [](const pair<char, int>& a, const pair<char, int>& b){
            return a.second < b.second;
        });
    for(auto it : mapV) {
        cout << it.first << " : " << it.second << endl;
    } */

    return v;
}

vector<char> sortByFreq(vector<char>& v) {
    // using vector to save the repeat times of each character
    // freq['a'] = 4;
    // freq['b'] = 6;
    // vector<char>

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

// TODO 运算符重载