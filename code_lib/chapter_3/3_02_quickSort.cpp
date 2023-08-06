struct Interval {
    int start, end;
};

// 1. 使用qsort库函数
int compareInterval(const void* a, const void* b) {
    Interval* intervalA = (Interval*)a;
    Interval* intervalB = (Interval*)b;
    return (intervalA->start - intervalB->start);
}

void test() {
    string s = "abxyazc";
    sort(s.begin(), s.end());
    cout << s << endl;
}

// 2. 自己实现
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

void quickSort(int *nums, int start, int end) {
    if(start < end) {
        int pivot;
        pivot = parititon(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

int main(void) {
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    // std::sort(arr, arr + n, compareInterval);
    std::qsort(arr, n, sizeof(arr[0]), compareInterval);

    for(auto x : arr) {
        cout << x.start << " " << x.end << " ";
        cout << endl;
    }

    test();

    return 0;
}