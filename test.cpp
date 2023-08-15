#include "test.hpp"

#if 0
int partition(vector<int> nums, int left, int right) {
    int save = nums[left];
    while (left < right) {
        while (left < right && nums[right] <= save) {
            right--;
        }
        if (left < right) {
            nums[left++] = nums[right];
        }
        while (left < right && nums[left] >= save) {
            left++;
        }
        if (left < right) {
            nums[right--] = nums[left];
        }
    }
    nums[left] = save;
    return left;
}

void quickSort(vector<int> nums, int left, int right, int k, int& pivot) {
    pivot = partition(nums, left, right);
    if (pivot == k) {
        return;
    }
    if (pivot < k) {
        quickSort(nums, pivot + 1, right, k, pivot);
    } else {
        quickSort(nums, left, pivot - 1, k, pivot);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    int res;
    quickSort(nums, 0, nums.size() - 1, k - 1, res);
    return nums[res];
}
#endif

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
        
        if (k <= left.size()) {
            return quickSelect(left, k);
        }
        
        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }
        
        return pivot;
    }
};

#if 0
int main(void) {
    Solution2 sol;
    // vector<int> nums = {1, 8, 6, 3, 7, 2, 0, 4, 5, 9};
    vector<int> nums = {1, 1, 2, 2, 1};
    cout << sol.findKthLargest(nums, 1) << endl;

    for(int i = 0; i < 15; i++) {
        // cout << rand() % 15 << endl;
    }


    return 0;
}
#endif

// ----- 3. partition - 1
int partition(vector<int>& nums, int start, int end) {
    int left = start - 1;
    int right;
    int pivot = nums[end];

    for(right = start; right < end; right++) {
        if(nums[right] < pivot) {
            left++;
            std::swap(nums[left], nums[right]);
        }
    }
    std::swap(nums[left + 1], nums[end]);
    return left + 1;
}

void quickSort(vector<int>& nums, int start, int end) {
    if(start < end) {
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

// ------ 4. partition - 2

void sortedSquares(vector<int> nums, vector<int>& res) {
    int left = 0;
    int right = nums.size() - 1;
    
    for(int i = 0; i < nums.size(); i++) {
        int lSquare = nums[left] * nums[left];
        int rSquare = nums[right] * nums[right];

        if(lSquare > rSquare) {
            // res.push_back(lSquare);
            res.insert(res.begin(), lSquare);
            left++;
        } else {
            res.insert(res.begin(), rSquare);
            right--;
        }
    }
}


int main(void) {
    Solution2 sol;
    vector<int> nums = {1, 8, 6, 3, 7, 2, 0, 4, 5, 9};
    // vector<int> nums = {-10, -8, -6, -30, 1, 2, 6, 8, 10, 11};    
    // cout << sol.findKthLargest(nums, 3) << endl;
    quickSort(nums, 0, nums.size());
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    // vector<int> res;
    // sortedSquares(nums, res);

    // for(int i = 0; i < res.size(); i++) {
    //     cout << res[i] << endl;
    // }

    


    return 0;
}