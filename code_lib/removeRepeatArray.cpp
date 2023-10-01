
/*
    排序后的数组（非递减数组），去除重复字符，返回去重后的数组
        如果是未排序的数组，则先排序即可！
*/

int lenOfNorep(vector<int>& nums) {
    int count = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            nums[count] = nums[i];
            count++;
        }
    }
    nums.resize(count);
    return count;
}

int main(void) {
    vector<int> nums = {1, 2, 2, 3, 4};

    cout << lenOfNorep(nums) << endl;

    // using iterator to travel
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        cout << *it << endl;
    }

    for(auto x : nums) {
        cout << x << endl;
    }

    return 0;
}