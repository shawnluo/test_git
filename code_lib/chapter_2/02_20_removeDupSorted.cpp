// remove duplicated element from a array

int LenOfRemoveDuplicates(int arr[], int n) {
    if (n == 0)
        return 0;

    int i, j = 0;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1]; // Include the last element

    return j;
}

int LenOfRmDup(vector<int> arr) {
    int len = arr.size();
    vector<int> dp(len, 0);
    dp[0] = 1;

    for(int i = 1; i < len; i++) {
        if(arr[i] != arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[len - 1];
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int length = removeDuplicates(arr, n);

    printf("Array without duplicates: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}