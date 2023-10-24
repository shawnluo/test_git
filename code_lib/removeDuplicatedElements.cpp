void removeDuplicatedElements() {
    vector<int> nums = {1, 1, 2, 1, 3, 4, 2};
    int k = 1;;
    for(int i = 1; i < nums.size(); i++) {
        int j;
        for(j = 0; j < i; j++) {
            if(nums[i] == nums[j]) {
                break;
            }
        }
        if(i == j) {
            nums[k++] = nums[i];
        }
    }
    nums.resize(k);
    for(auto it : nums) {
        cout << it << endl;
    }
}

int main(void) {
    removeDuplicateElements();

    return 0;
}