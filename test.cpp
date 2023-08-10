#include "test.hpp"



//TODO: find the smallest difference between 2 elements in a unsorted array
// 1. use normal way
int minDif(vector<int> nums) {
    int res = INT_MAX;
    int len = nums.size();
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < i; j++){
            res = min(abs(nums[i] - nums[i - 1]), res);
        }
    }
    return res;
}

// 2. use dp 
// 这与上面的常规方法的思路截然不同。
//      dp: 当取 0 ~ i时，两数的差最小值
int minDif_dp(vector<int> nums) {
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    dp[1] = abs(nums[0] - nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        for(int j = 1; j < i; j++) {
            // dp[i] = min(dp[i], min(dp[i - j], abs(nums[i] - nums[j])));
            dp[i] = min(dp[i], min(dp[j], abs(nums[i] - nums[j])));
        }
    }
    return dp[nums.size() - 1];
}

int countValidPairs(vector<int> nums, int threshold) {
    int len = nums.size();
    int i = 0;
    int count = 0;
    while(i < len - 1) {
        if(nums[i + 1] - nums[i] <= threshold) {
            i++;
            count++;
        }
        i++;
    }
    return count;
}

int findMaxInMinDiff(vector<int> nums, int p) {
    std::sort(nums.begin(), nums.end());
    int len = nums.size();
    int left = 0;   // we can start from nums[1] - nums[0], but from 0 can simplify the code
    int right = nums[len - 1] - nums[0];

    while(left < right) {
        int mid = (left + right) / 2;
        if(countValidPairs(nums, mid) >= p) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}


int search(vector<int>& nums, int target) {
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    int mid = (left + right) / 2;
    if(nums[mid] == target) {
        while(mid && nums[mid - 1] == nums[mid]) {
            mid--;
        }
        return mid;
    }
    if(target > nums[mid]) {
        if(target <= nums[right]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}


void rotateArray(vector<int> &nums, int k) {
    int len = nums.size();
    // for(int i = 0; i < k; i++) {
    //     int tmp = nums[len - 1];

    //     for(int j = len - 1; j >= 1; j--) {
    //         nums[j] = nums[j - 1];
    //     }
    //     nums[0] = tmp;
    // }

    nums.insert(nums.end(), nums.begin(), nums.end());
    nums.assign(nums.begin() + (len - k % len), nums.end() - k % len);  // assign: 从nums中获取从len - k % len开始的，长度为len的元素，赋值给nums
                                                                        //         会把nums之前的内容替代掉！

    for(auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

void rotateArray_2(vector<int>& nums, int k) {

}


// nums 是升序的，但是被轮转了k, 找出k
// solution: nums[mid - 1] > nums[mid], mid就是解
int findRotate(vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;

    while(left < right) {
        int mid = (left + right) / 2;
        if(nums[mid - 1] > nums[mid]) {
            return mid;
        } else if(nums[mid] < nums[right]){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 5};
    // nums.erase(nums.begin(), nums.end() - 1);
    // for(auto x : nums) {
    //     cout << x << endl;
    // }
    // cout << findMaxInMinDiff(nums, 3) << endl;
    // cout << minDif_dp(nums) << endl;
    // printf("%d\n", rmDup(arr, 5));
    rotateArray(nums, 1);

    return 0;
}