#include "../test.hpp"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;

        // no overlapping before ther merge
        while(i < n && newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }

        // meet overlapping
        while(i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        // no overlapping after merged
        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};