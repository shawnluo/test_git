#include "test.hpp"

#include <iostream>
#include <cstdlib>


vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int, int> map;
	vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        auto x = map.find(target - nums[i]);
        if(x != map.end()) {
            // res.insert(res.end(), i, x->second);
			// cout << i << x->second << endl;
			return {x->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
}

int fourSum(vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
	unordered_map<int, int> map;
	int count = 0;

	for(int i = 0; i < a.size(); i++) {
		map[a[i] + b[i]]++;
	}
	for(int i = 0; i < a.size(); i++) {
		auto x = map.find(0 - c[i] - d[i]);
		if(x != map.end()) {
			count += x->second;
		}
	}
	return count;
}

bool ransom(string s, string sub) {
	int hash[256] = {0};
	for(int i = 0; i < s.size(); i++) hash[s[i]]++;

	for(int i = 0; i < sub.size(); i++) {
		if(hash[sub[i]]-- < 0) return false;
	}
	return true;
}

vector<vector<int>> threeAdd(vector<int> nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] > 0) break;
		if(i > 0 && nums[i] == nums[i - 1]) continue;

		int left = i + 1;
		int right = nums.size() - 1;
		while(left < right) {
			if(nums[i] + nums[left] + nums[right] > 0) {
				right--;
			} else if(nums[i] + nums[left] + nums[right] < 0) {
				left++;
			} else {
				res.push_back(vector<int>{nums[i], nums[left], nums[right]});

				while(right > left && nums[right] == nums[right - 1]) right--;
				while(right > left && nums[left] == nums[left + 1]) left--;

				right--;
				left++;
			}
		}
	}
	return res;
}

int search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while(left <= right) {
		int mid = (left + right) / 2;

		if(nums[mid] > target) {
			right = mid - 1;
		} else if(nums[mid] < target) {
			left = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int rm_eliment(vector<int>& nums, int val) {
	int left = 0;

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != val) {
			nums[left++] = nums[i];
		}
	}
	nums.resize(left);
	return left;
}

vector<int> sortSq(vector<int> nums) {
	int left = 0;
	int right = nums.size() - 1;
	int size = nums.size() - 1;
	vector<int> res(nums.size(), 0);

	while(left <= right) {
		if(pow(nums[left], 2) > pow(nums[right], 2)) {
			res[size--] = pow(nums[left], 2);
		} else {
			res[size--] = pow(nums[right], 2);
		}
	}
	return res;
}

vector<int> minLen(vector<int> nums, int s) {
	int res = INT_MAX;
	int sum = 0;
	int i = 0;
	int subSize = 0;

	for(int j = 0; j< nums.size(); j++) {
		sum += nums[j];
		while(sum >= s) {
			subSize = j - i + 1;
			res = max(res, subSize);
			sum -= nums[i++];
		}
	}
	return res == INT_MAX ? 0 : res;
}

int main() {
	vector<int> a = {2, 1, 3};
	vector<int> b = {-2, -1, 3};
	vector<int> c = {2, -1, 3};
	vector<int> d = {-2, -1, 3};

	cout << fourSum(a, b, c, d) << endl;
    // vector<int> arr = {2, 1, 3, 6, 5, 4, 7};
    // int n = 7;
	// vector<int> res = twoSum(arr, n);
	// for(auto x : res) {
	// 	cout << x << endl;
	// }

	return 0;
}