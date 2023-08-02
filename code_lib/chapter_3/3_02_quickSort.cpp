struct Interval {
    int start, end;
};

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