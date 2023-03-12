#include "common.h"
#include "test.h"

int *find_anagrams(char *s, char *sub) {
    int len_s = strlen(s);
    int len_sub = strlen(sub);
    int hash[256] = {0};

    for(int i = 0; i < len_sub; i++) {
        hash[sub[i]]++;
    }
    int count = len_sub;
    int left = 0, right = 0;
    static int res[10];

    count = 0;
    while(right < len_s) {
        if(hash[s[right++]]-- >= 1) {
            count--;
        }
        if(count == 0) {
            res[count++] = left;
        }

        if(right - left == len_sub && hash[s[left++]]++ >= 0) {
            count ++;
        }
    }
}

bool check_inclusion(char *s, char *sub) {
    int len_s = strlen(s);
    int len_sub = strlen(sub);
    int hash[256] = {0};
    for(int i = 0; i < len_sub; i++) {
        hash[sub[i]]++;
    }

#if 1
    for(int i = 0; i < len_s; i++) {
        hash[s[i]]--;
        if(i >= len_sub) {
            hash[s[i - len_sub]]++;
        }
        int j;
        for(j = 0; j < 256; j++) {
            if(hash[j] != 0)   break;
        }
        if(j == 256)    return true;
    }
    #endif
    return false;
}

bool check_inclusion_e(char *s, char *sub) {
    int len_s = strlen(s);
    int len_sub = strlen(sub);
    int hash[256] = {0};
    for(int i = 0; i < len_sub; i++) {
        hash[sub[i]]++;
    }
    int left = 0, right = 0;
    int count = 0;
    while(right < len_s) {
        if(hash[s[right++]]-- >= 1)     count++;
        if(count == len_sub)            return true;
        if(right - left >= len_sub && hash[s[left++]]++ >= 0)   count--;
    }
    return false;
}

int longest_increasing(int *nums, int size) {
    int dp[size];
    for(int i = 0; i < size; i++)   dp[i] = 1;

    int res = 0;
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; i++) {
            if(nums[i] > nums[j])   dp[i] = fmax(dp[i], dp[dp[j] + 1]);
        }
        res = fmax(res, dp[i]);
    }
    return res;
}

int max_sum(int *nums, int size) {
    int dp[size];
    dp[0] = nums[0];
    int res = INT_MIN;
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = fmax(dp[i - 1] + nums[i], nums[i]);
        }
        res = fmax(res, dp[i]);
    }
    return res;
}


void fun(int n) {
    if(n > 2) {
        fun(n - 1);
        fun(n - 2);
        fun(n - 3);
    }
    printf("%d\n", n);
}

void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void permutation(char *s, int start) {
    int size = strlen(s);
        
    //if(start == size)
        printf("%s\n", s);

    for(int i = start; i < size; i++) {
        swap(s + i, s + start);
        permutation(s, start + 1);
        swap(s + i, s + start);
    }
}

int partition_2(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high -1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);
    return i + 1;
}

void quick_sort_2(int *arr, int low, int high) {
    if(low < high) {
        int pivot = partition_2(arr, low, high);
        quick_sort_2(arr, low, pivot - 1);
        quick_sort_2(arr, pivot + 1, high);
    }
}


int main(void) {
    //char *s = "xabcy";
    //char *sub = "acpb";
    //bool res = check_inclusion_e(s, sub);
    //printf("%d\n", res);
    //fun(5);

    char s[] = "abc";
    permutation(s, 0);

    return 0;
}