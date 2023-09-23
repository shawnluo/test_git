void sortedSquares(vector<int> nums, vector<int>& res) {
    int left = 0;
    int right = nums.size() - 1;
    
    for(int i = 0; i < nums.size(); i++) {
        int lSquare = nums[left] * nums[left];
        int rSquare = nums[right] * nums[right];

        if(lSquare > rSquare) {
            // res.push_back(lSquare);
            res.insert(res.begin(), lSquare);
            left++;
        } else {
            res.insert(res.begin(), rSquare);
            right--;
        }
    }
}


int main(void) {
    Solution2 sol;
    // vector<int> nums = {1, 8, 6, 3, 7, 2, 0, 4, 5, 9};
    vector<int> nums = {-10, -8, -6, -3, 1, 2, 6, 8, 10, 11};    
    // cout << sol.findKthLargest(nums, 3) << endl;
    // quickSort(nums, 0, nums.size());

    vector<int> res;
    sortedSquares(nums, res);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    


    return 0;
}