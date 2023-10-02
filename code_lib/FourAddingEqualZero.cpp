int FourAdding(vector<int> A, vector<int> B, vector<int> C, vector<int> D) {
    // 1. unordered_map<int> map; key: sum of a + b, value: the repeat times of key
    unordered_map<int, int> map;

    for(int a : A) {
        for(int b : B) {
            map[a + b]++;
        }
    }

    int count = 0;

    for(int c : C) {
        for(int d : D) {
            if(map.find(0 - c - d) != map.end()) {
                count += map[0 - c - d];
            }
        }
    }

    return count;
}

int main(void) {
    vector<int> nums1{1, 2, 3, 4};
    vector<int> nums1{1, 2, 3, 4};
    vector<int> nums1{1, 2, 3, 4};
    vector<int> nums1{1, 2, 3, 4};

    cout << FourAdding(nums1, nums2, nums3, nums4) << endl;

    for(auto x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}