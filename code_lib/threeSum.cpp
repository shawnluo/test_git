
// 找出所有三个数和等于0的组合，去重


vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> res;
    // 1. sort
    sort(nums.begin(), nums.end());
    // 2. for loop travesal - p1
    // 3. pointer 2 from p1 + 1
    // 4. pointer 3 from nums.end()

    int size = nums.size();
    for(int i = 0; i < size; i++) {
        if(nums[i] > 0) {
            break;
        }
        // sum += nums[i];
        // buf.push_back(nums[i]);
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int j = i + 1;
        int k = size - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                res.push_back({nums[i], nums[j], nums[k]});
                if(j < k && nums[j] == nums[j - 1]) {
                    j++;
                } 
                if(j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
                j++, k--;
            }
        }
    }
    return res;
}


int main(void) {
    vector<int> num{-2, 1, 1, 5, -6};
    vector<vector<int>> res = threeSum(num);

    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}