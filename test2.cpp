#include "test.hpp"



bool customSort(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

vector<vector<int>> merge_intervers(vector<vector<int>>& v) {
    sort(v.begin(), v.end(), customSort);
    int n = v.size();

    int L = v[0][0];
    int R = v[0][1];
    int index = 0;
    vector<vector<int>> res(n, vector<int>(2));

    for(int i = 1; i < n; i++) {
        if(v[i][0] >= L && v[i][0] <= R && v[i][1] > R) {
            R = v[i][1];
        } else if(v[i][1] <= R) {
            res[index][0] = L;
            res[index][1] = R;
            index++;
        }
    }
    res[index][0] = L;
    res[index][0] = R;
    index++;

    res.resize(index);
    return res;
}

vector<vector<int>> insert_interver(vector<vector<int>>& v, vector<int> vn) {
    int n = v.size();
    int i = 0;
    vector<vector<int>> res;

    // 1. push units before overlapping
    while(i < n && vn[0] > v[i][1]) {
        res.push_back(v[i]);
        i++;
    }

    // 2. merge overlapping
    while(i < n && vn[1] >= v[i][0]) {
        vn[0] = min(vn[0], v[i][0]);
    }

    // 3. push units after overlapping


}

int main(void) {
    vector<vector<int>> v = {{6, 3}, {6, 2}, {2, 1}, {2, 5}, {6, 0}};
    
    sort(v.begin(), v.end(), customSort);

    for(auto it : v) {
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}