#include "test.hpp"

// using namespace std;

vector<vector<int>> findTwo(vector<int> nums, int val) {
    unordered_map<int, int> num_map;
    // for(auto x : nums) {
    //     num_map[x] = 1;
    // }

    vector<vector<int>> res;
    vector<int> save;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(nums[i] + nums[j] == val) {
                
                if(num_map[nums[i]] == 0 && num_map[nums[j]] == 0) {
                    num_map[nums[i]] = 1;
                    num_map[nums[j]] == 1;
                    save.clear();
                    save.push_back(nums[i]);
                    save.push_back(nums[j]);
                    res.push_back(save);
                }
            }
        }
    }

    return res;
}

vector<vector<int>> findThree(vector<int>& nums, int val) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    int size = nums.size();
    int left = 1;
    int right = size - 1;
    int sum = 0;
    vector<int> buf;

    for(int i = 0; i < size - 2; i++) {
        if(nums[i] > val) {
            return res;
        }

        if(i > 0 && nums[i - 1] == nums[i]) {   // this is the right way to get ride of repeat
            continue;
        }

        sum = 0;
        while(left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if(sum == val) {
                res.push_back(vector<int> {nums[i], nums[left], nums[right]});

                // deal with the duplicates: pass the duplicated numbers
                while(left < right && nums[right - 1] == nums[right]) {
                    right--;
                }
                while(left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                left++, right--;
            } else if(sum < val) {
                left++;
            } else {
                right--;
            }
        }
    }

    return res;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int k = 0; k < nums.size(); k++) {
        if(nums[k] > target && nums[k] >= 0) {
            break;
        }
        if(k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }
        for(int i = k + 1; i < nums.size(); i++) {
            if(nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                break;
            }
            if(i > k + 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[k] + nums[i] + nums[left] + nums[right];
                if(sum == target) {
                    res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                    // 去重
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++, right--;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 1, 1, 2, 4};
    // vector<vector<int>> res = findTwo(nums, 8);
    vector<vector<int>> res = findThree(nums, 8);
    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}