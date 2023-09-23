

// 找到并返回第k大的元素。并非其位置！

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int num: nums) {
            heap.push(-num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        return -heap.top();
    }
};


// TODO
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
    
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        
        vector<int> left;
        vector<int> mid;
        vector<int> right;
        
        for (int num: nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        
        if (k <= left.size()) { // 如果比pivot大的集合 等于多于 给定的k.
            return quickSelect(left, k);
        }
        
        if (left.size() + mid.size() < k) { // 如果比pivot大和相等的集合 小于k
            return quickSelect(right, k - left.size() - mid.size());
        }

        // 退出条件：举例   1, 1, 2, 1, 2, 3   
        //              k   :   2
        // 1. found "2" first time
        //              left:   1, 1, 1
        //              mid:    2, 2
        //              right:  3
        // 2. then run quickSelect in left
        //              left: 1

        //          1. 左边集合存放的是：比pivot大的数的集合。其数量，要少于k
        //          2. 中间集合存放的是：和pivot一样大的数。  其集合，        
        return pivot;
    }
};

// ----- 3. partition - 1
int partition(vector<int>& nums, int start, int end) {
    int left = start - 1;
    int right;
    int pivot = nums[end];

    for(right = start; right < end; right++) {
        if(nums[right] < pivot) {
            left++;
            swap(nums[left], nums[right]);
        }
    }
    swap(nums[left + 1], nums[end]);
    return left + 1;
}

// ------ 4. partition - 2
int partition() {
    
}


void quickSort(vector<int>& nums, int start, int end) {
    if(start < end) {
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}



int main(void) {
    Solution2 sol;
    vector<int> nums = {1, 8, 6, 3, 7, 2, 0, 4, 5, 9};
    // cout << sol.findKthLargest(nums, 3) << endl;
    quickSort(nums, 0, nums.size());

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}