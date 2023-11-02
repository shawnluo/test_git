#include "test.hpp"

void rmDump() {
    vector<int> nums = {1, 2, 1, 3, 2, 1};
    int size = nums.size();
    int pos = 0;

    for(int i = 0; i < size; i++) {
        int j;
        for(j = 0; j < i; j++) {
            if(nums[i] == nums[j]) {
                break;
            }
        }
        if(j == i) {
            nums[pos++] = nums[i];
        }
    }
    nums.resize(pos);
    for(auto it : nums) {
        cout << it << " ";
    }
    cout << endl;
}

int main(void) {
    rmDump();

    return 0;
}