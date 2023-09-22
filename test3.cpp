
#include "test.hpp"

// abcddef -> abcd 
// return 4
int longestUniqSub(string s) {
    int pos = -1;
    int len = 0;
    int res = 0;

    int hash[256];
    for(int i = 0; i < 256; i++) hash[i] = -1;

    for(int i = 0; i < s.size(); i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}



int main(void) {
    Solution sol;
    vector<int> nums1 = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> nums2 = {2, 3, 5, 7, 11, 13, 17, 19};
    
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    
    return 0;
}