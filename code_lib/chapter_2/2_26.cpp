


//sorted
void test(vector<int>& nums) {
    // vector<int> nums{1, 1, 1, 1, 2, 3, 3, 5};
    int slow = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {    // 技巧：根据nums[i] 与 nums[i - 1]的比较，可以
            nums[++slow] = nums[i];
        }
    }
    for(int i = 0; i <= slow; i++) {
        cout << nums[i] << endl;
    }
}

// unsorted
void test_2() {
    vector<int> nums{1, 6, 1, 1, 2, 3, 2, 5, -1, 1};
    sort(nums.begin(), nums.end());

    test(nums);

    // for(auto x : nums) {
    //     cout << x << endl;
    // }
}

int main(void) {
    test_2();

    return 0;
}