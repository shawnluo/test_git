
// leetcode 33
/*
Given  a sorted  array  of  n  integers  that  has  been  rotated  an  unknown  number  of times,
give an O(log n) algorithm that finds an element in the array
You may assume that the array was originally sorted in increasing order

EXAMPLE:Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)Output: 8 (the index of 5 in the a
*/

int search(vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;
    for (; left <= right;) {
        int mid = (left + right) / 2;
        if (nums[mid] == val) {
            return mid;
        }
        // 如果 中数小于最右边的数，那么 - 右半段是有序的！ - 看看是不是在右边
        if (nums[mid] < nums[right]) {
            if (val > nums[mid] && val <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // 如果 中数大于最右边的数，那么 - 左半段是有序的！ - 看看是不是在左边
        else {
            if (val < nums[mid] && val >= nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    cout << test(nums, 0);
    // cout << s << endl;

    return 0;
}