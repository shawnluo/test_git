/*
leetcode 35. Search Insert Position
Solved
Easy
Topics
Companies
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lhs = 0;
        int rhs = n - 1;

        for(; lhs <= rhs;) {    // 也可以用<, 但是最后需要返回rhs
            // int mid = (lhs + rhs) >> 1;
            int mid = lhs + ((rhs - lhs) >> 1);
            if(target < nums[mid]) {
                rhs = mid - 1;
            } else if (target > nums[mid]) {
                lhs = mid + 1;
            } else {
                return mid;
            }
        }

        /*
         * 四种情况
         * 1. target在数组所有元素之前          return right + 1        0
         * 2. target等于数组中的某一个元素      return mid
         * 3. target插入数组中的某个位置        return right + 1
         * 4. target在数组所有元素之后          return right + 1        n
         */ 

        return rhs + 1;
    }
};