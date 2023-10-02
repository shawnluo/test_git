
#include "test.hpp"

unordered_set<int> interSection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> res;
    unordered_set<int> set(nums1.begin(), nums1.end());

    for(int num : nums2) {
        if(set.find(num) != set.end()) {
            res.insert(num);
        }
    }
    // return vector<int>(res.begin(), res.end());
    return res;
}

vector<int> towSum(vector<int>& nums, int target) {
    unordered_map <int, int> map;

    for(int i = 0; i < nums.size(); i++) {
        auto iter = map.find(target - nums[i]);
        if(iter != map.end()) {
            return {iter->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
}

int main(void) {
    // vector<int> nums1 = {1, 2, 2, 1};
    // vector<int> nums2 = {2, 2};

    // unordered_set<int> res = interSection(nums1, nums2);

    // for(auto x : res) {
    //     cout << x << " ";
    // }
    // cout << endl;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int>res = towSum(nums, target);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}