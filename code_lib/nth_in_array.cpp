class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int res = quickSort(nums, 0, nums.size() - 1, k - 1);
        priority_queue<int> heap;
        for(auto num : nums) {
            heap.push(-num);
            if(heap.size() > k) {
                heap.pop();
            }
        }
        return -heap.top();
    }
};