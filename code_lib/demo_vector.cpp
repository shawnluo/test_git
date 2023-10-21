

vector<vector<int>> res;

res.push_back(vector<int>{nums[i], nums[j], nums[k]});

// first element
cout << nums.front() << endl;

// last element
cout << nums.back() << endl;

bool findInVec(int n) {
    vector<int> nums = {1, 2, 3};
    if(std::find(nums.begin(), nums.end(), 3) != nums.end()) {
        // cout << 1 << endl;
        return true;
    }
    return false;
}
