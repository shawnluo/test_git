
#include "../test.hpp"

bool customSort(const vector<int> a, const vector<int> b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

vector<vector<int>> v = {{6, 3}, {6, 5}, {2, 1}, {2, 5}, {6, 0}};
void sort(vector<vector<int>>& v) {
    sort(v.begin(), v.end(), customSort);
}