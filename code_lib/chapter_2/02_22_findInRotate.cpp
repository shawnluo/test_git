


// sorted nums[], 旋转了未知次(k)，找到target，如果结果不止一个，返回index最小的
int search(vector<int> nums, int target) {
    int len = nums.size();
    int left = 0;
    int right = len - 1;

    while(left <= right) {
        int mid = (left + right ) >> 1; // 除以2
        if(nums[mid] == target) {
            while(mid >= 0 && nums[mid - 1] == nums[mid]) {  // 找到跟nums[mid]一样的元素，直到不同
                mid--;
            }
            return mid;
        }

        // 只要考虑三种情况
        // 1. 中间值小于右边值
        // 2. 中间值大于右边值
        // 3. 中间值等于右边值  -- 直接略过

        if(nums[mid] < nums[right]) {
            if(target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if(nums[mid] > nums[right]) {
            if(target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {    //中间节点与其右边的所有的节点都相等，那么略过。right = mid - 1
            right--; // 因为mid == right.所以这两句是一样的
            // right = mid - 1;
        }
    }
    return -1;
}