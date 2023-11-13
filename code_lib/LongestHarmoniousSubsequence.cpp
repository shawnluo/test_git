#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

/*
594. Longest Harmonious Subsequence
Solved
Easy
Topics
Companies
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Example 2:

Input: nums = [1,2,3,4]
Output: 2
Example 3:

Input: nums = [1,1,1,1]
Output: 0
 

Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
*/


// 思路：将数字出现的频率作为value放入字典。然后for循环中，找出字典中差别小于等于1的最大两个数列
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map;
        for(auto it : nums) {
            map[it]++;
        }

        for(auto key : map) {
            auto it = map.find(key.first + 1);
            if(it != map.end()) {
                res = max(res, key.second + it->second);
            }
        }
        return res;
    }
};