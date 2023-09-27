

int partition(int *nums, int start, int end) {
    int pivot = nums[start];
    while(start < end) {
        while(nums[end] >= pivot) {
            end--;
        }
        if(start < end) {
            nums[start++] = nums[end];
        }
        while(nums[start] <= pivot) {
            start++;
        }
        if(start < end) {
            nums[end--] = nums[start];
        }
    }
    nums[start] = pivot;
    return start;
}

// 3. 优化 partition函数
int partition_2(vector<int>& nums, int start, int end) {
    int left = start - 1;
    int right;
    int pivot = nums[end];

    for(right = start; right < end; right++) {
        if(nums[right] < pivot) {
            left++;
            std::swap(nums[left], nums[right]);
        }
    }
    std::swap(nums[left + 1], nums[end]);
    return left + 1;
}


void quickSort(int *nums, int start, int end) {
    if(start < end) {
        int pivot;
        pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

int main(void) {
    // 1. sort array pairs
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1.1 by using sort
    std::sort(arr, arr + n, compareInterval);
    
    // 1.2 using qsort
    std::qsort(arr, n, sizeof(arr[0]), compareInterval);

    // 2. sort array
    vector<int> arr = {2, 1, 7, 5};
    quickSort(arr, 0, arr.size() - 1);

    for(auto x : arr) {
        cout << x.start << " " << x.end << " ";
        cout << endl;
    }

    test();

    return 0;
}