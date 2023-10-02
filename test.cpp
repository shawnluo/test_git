#include "test.hpp"

int removeVal(vector<int>& nums, int val) {
    int left = 0;
    int right = 0;

    for(int right = 0; right < nums.size(); right++) {
        if(nums[right] != val) {
            nums[left++] = nums[right];
        }
    }
    nums.resize(left);
    return left;
}

int removeVal_ext(vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;

    while(left < right) {
        while(left < right && nums[left] != val) {
            left++;
        }
        while(left < right && nums[right] == val) {
            right--;
        }
        if(left < right) {
            nums[left++] = nums[right--];
        }
    }
    return left;
}

vector<int> twoSum_BF(vector<int> nums, int target) {
    // unordered_set<int> set;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                return res;
            }
        }
    }
    return {};
}

int main(void) {
    vector<int> nums{1, 32, 6, 8, 0, 4, 6, 43};
    cout << removeVal(nums, 6) << endl;

    for(auto x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}