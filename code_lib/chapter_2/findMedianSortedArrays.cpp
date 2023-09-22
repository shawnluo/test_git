
#include "test.hpp"

/*
leetcode 4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    // 其思路是不必合并两个数组，只需要找到两个数组长度之和的中间元素。用p1和p2来定位。

    int p1 = 0, p2 = 0; // 这两个全局变量是用来移动指向nums1和nums2.

    // Get the smaller value between nums1[p1] and nums2[p2] and move the pointer forward.

    int getMin(vector<int>& nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        } 
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());
        
        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) { // p1 和 p2会移动到中间元素之前的一个元素
                int _ = getMin(nums1, nums2);
                // cout << _ << endl;
            }
            
            // 再继续执行getMin()，如果两个数组长度和是偶数元素的话，会移动到中间元素的左右
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int _ = getMin(nums1, nums2);
            }
            // 再继续执行getMin()，如果两个数组长度和是奇数元素的话，会移动到中间元素
            return getMin(nums1, nums2);
        }
            
        return -1;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums1 = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> nums2 = {2, 3, 5, 7, 11, 13, 17, 19};
    
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    
    return 0;
}