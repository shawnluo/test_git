#include "test.hpp"

class Solution {
public:
    int split(const vector<int> num) {
        return 0;
    }
};

int main(void) {
    Solution solution;
    int arr[] = {1, 4, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    const vector<int> num(arr, arr + size);
    for(int x : num) {
        cout << x << endl;
    }
    int res = solution.split(num);
    cout << res << endl;

    return 0;
}