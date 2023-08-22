#include "test.hpp"

// using namespace std;

int do_search(vector<int> nums, int start, int end, int target) {
    if(start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if(nums[mid] == target) {
        return mid;
    }
    if(target < nums[mid]) {
        return do_search(nums, start, mid - 1, target);
    } else {
        return do_search(nums, mid + 1, end, target);
    }
}

//TODO fix this 
int searchRe(vector<int> nums, int target) {
    return do_search(nums, 0, nums.size() - 1, target);

}
int main(void) {
    vector<int> nums{1, 3, 5, 9};
    int target = 19;
    int ret = searchRe(nums, target);
    cout << ret << endl;

    return 0;
}