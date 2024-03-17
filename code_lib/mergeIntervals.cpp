#include "../test.hpp"

class Solution {
public:
    static bool customSort(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), customSort);

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
            });

        int L = intervals[0][0];
        int R = intervals[0][1];

        int n = intervals.size();
        vector<vector<int>> res(n, vector<int>(2, 0));
        int index = 0;

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= L && intervals[i][0] <= R && intervals[i][1] > R) {
                R = intervals[i][1];
            } else if(intervals[i][0] > R) {
                res[index][0] = L;
                res[index][1] = R;
                L = intervals[i][0];
                R = intervals[i][1];
                index++;
            }
        }
        res[index][0] = L;
        res[index][1] = R;
        index++;

        res.resize(index);

        return res;
    }
};