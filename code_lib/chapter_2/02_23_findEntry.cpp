

// nums 是升序的，但是被轮转了k, 找出k
// solution: nums[mid - 1] > nums[mid], mid就是解
int findRotate(const vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;

    while(left < right) {
        int mid = (left + right) >> 1;
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