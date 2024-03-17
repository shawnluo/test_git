#include "test.hpp"



bool customSort(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int main(void) {
    vector<vector<int>> v = {{6, 3}, {6, 2}, {2, 1}, {2, 5}, {6, 0}};
    
    sort(v.begin(), v.end(), customSort);

    for(auto it : v) {
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}