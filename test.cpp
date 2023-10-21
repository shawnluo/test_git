#include "test.hpp"

int array_02(vector<int> nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        map[i] = nums[i];
    }
    auto it = map.find(target);
    if(it != map.end()) {
        return it->second;
    }
    return -1;
}

int array_02_1(vector<int> nums, int target) {
    cout << nums.front() << endl;
    cout << nums.back() << endl;
    if(nums[0] > target || nums.back() < target) {
        return -1;
    }
    int size = nums.size();
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int mid = (left + right) >> 1;
        
        if(target < nums[mid]) {
            right = mid - 1;
        } else if(target > nums[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int array_03(vector<int>& nums, static int val) {
    int left = 0;

    for(int i = 0;i < nums.size(); i++) {
        if(nums[i] != val) {
            nums[left++] = nums[i];
        }
    }
    nums.resize(left);
    return left;
}

vector<int> array_04(vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;
    int count = 0;
    vector<int> res(nums.size());

    while(left < right) {
        if(pow(left, 2) > pow(right, 2)) {
            res[count++] = pow(left++, 2);
        } else {
            res[count++] = pow(right--, 2);
        }
    }
    return res;
}



int longestConIncreasingSub(vector<int> nums) {
    int res = 1;
    vector<int> dp(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        res = max(res, dp[i]);
    }
    return res;
}

int longestIncSub(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main(void) {
    vector<int> nums = {-1, 0, 2, 3};
    cout << array_02_1(nums, -2) << endl;

    return 0;
}

// int main(void) {
//     string s = "   show me   the   !   ";
//     reverseWords(s);

//     cout << s << endl;

//     return 0;
// }