#include "test.hpp"

// quick sorting for nums[]
void quickSort(vector<int>& nums, int start, int end) {
    if(start >= end) return;

    int pivot = nums[start];
    int L = start;
    int R = end;

    while(L < R) {
        while(nums[R] >= pivot && L < R) {
            R--;
        }
        if(L < R) {
            nums[L] = nums[R];
            L++;
        }
        while(nums[L] <= pivot) {
            L++;
        }
        if(L < R) {
            nums[R] = nums[L];
            R--;
        }
    }
    nums[L] = pivot;
    quickSort(nums, start, L - 1);
    quickSort(nums, L + 1, end);
}



int main(void) {
    vector<int> nums = {23, 8, 0, 123, 5};
    quickSort(nums, 0, nums.size() - 1);

    for(int i : nums) {
        cout << i << endl;
    }

    return 0;
}