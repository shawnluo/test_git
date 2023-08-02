



// This is better
void merge(vector<int>& A, const vector<int> B, int lastA, int lastB) {
    int indexA = lastA;
    int indexB = lastB;
    int mergeIndex = lastA + lastB + 1;
    while(lastB >= 0) {
        if(lastA >= 0 && A[indexA] > B[indexB]) {
            A[mergeIndex] = A[lastA];
            indexA--;
        } else {
            A[mergeIndex] = B[lastB];
            lastB--;
        }
        mergeIndex--;
    }
}


void merge_sorted(const vector<int> nums1, const vector<int> nums2, vector<int>& nums) {
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] <= nums2[j]) {
            nums.push_back(nums1[i]);
            i++;
        } else {
            nums.push_back(nums2[j]);
            j++;
        }
    }
    while(i < nums1.size()) {
        nums.push_back(nums1[i++]);
    }
    while(j < nums2.size()) {
        nums.push_back(nums2[j++]);
    }
}



int main(void) {
    vector<int> nums1 = {2, 8, 116, 198, 212, 500};
    vector<int> nums2 = {-10, 83, 100, 198, 256, 400};
    vector<int> nums;
    merge_sorted(nums1, nums2, nums);
    for(auto i : nums) {
        cout << i << endl;
    }

    return 0;
}