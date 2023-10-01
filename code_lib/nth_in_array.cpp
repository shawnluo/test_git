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


// ------------------- using partition


int partition(int* arr, int start, int end) {
    int j = start - 1;

    for(int i = start; i < end; i++) {
        if(arr[i] < arr[end]) {
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[j + 1], arr[end]);
    return j + 1;
}

void myQsort(int *arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        myQsort(arr, start, pivot - 1);
        myQsort(arr, pivot + 1, end);
    }
}

int do_getNth(int* arr, int start, int end, int k) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        if(k == pivot) return arr[pivot];
        
        if(k < pivot)   return do_getNth(arr, start, pivot - 1, k);
        else            return do_getNth(arr, pivot + 1, end, k);
    }
    return -1;
}

int getNth(int *arr, int len, int k) {
    k = len - k + 1;    // 第k个最大的数。举例：第2个最大的数 5 - 2 + 1 = 4
    return do_getNth(arr, 0, len - 1, k);
}

int main(void) {
    int arr[] = {2, 1, 3, 6, 5, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size << endl;
    myQsort(arr, 0, size);
    for(auto x : arr) {
        cout << x << " ";
    }
    cout << endl;

    cout << getNth(arr, size, 4) << endl;

    return 0;
}