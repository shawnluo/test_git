

vector<int> interSection(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> res;
    unordered_set<int> set(nums1.begin(), nums1.end());

    for(auto x : nums2) {
        if(set.find(x) != set.end()) {
            res.insert(x);
        }
    }
    return vector<int>(res.begin(), res.end());
}