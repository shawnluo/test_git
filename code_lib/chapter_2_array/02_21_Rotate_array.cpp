
// 方法1. 暴力
void rotateArray(vector<int> &nums, int k) {
    int len = nums.size();
    for(int i = 0; i < k; i++) {
        int tmp = nums[len - 1];

        for(int j = len - 1; j >= 1; j--) {
            nums[j] = nums[j - 1];
        }
        nums[0] = tmp;
    }
}

// 方法2. 将数组拷贝后，拼在一起。
//          然后删除前n - k个，删除后面k个
void rotateArray(vector<int> &nums, int k) {
    nums.insert(nums.end(), nums.begin(), nums.end());
    nums.assign(nums.begin() + (len - k % len), nums.end() - k % len);  // assign: 从nums中获取从len - k % len开始的，长度为len的元素，赋值给nums
                                                                        //         会把nums之前的内容替代掉！

    for(auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}