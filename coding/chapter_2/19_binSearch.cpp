

// leetcode 704

int search(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;

    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}