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
    int res = INT_MIN;
    dp[0] = nums[0];

    for(int i = 1; i < size; i++) {
        dp[i] = fmax(dp[i - 1] + nums[i], dp[i]);            
        res = fmax(res, dp[i]);
    }
    return res;
}


int book_meeting_room(int arr[][2], int size) {
    int start[size];
    int end[size];
    //1. sorting start and end


    while(pStart != size) {
        if(pStart == 0 || start[pStart] < end[pEnd]) {
            room++;
        } else {
            pEnd++;
        }
        pStart++;
    }
    return room;
}


int book_meeting_room(int arr[][2], int size) {
    int start[size];
    int end[size];
    for(int i = 0; i < size; i++) {
        start[i] = arr[i][0];
        end[i] = arr[i][1];
    }

    int pStart = 0;
    int pEnd = 0;
    int room = 0;
    while(pStart < size) {
        if(pStart == 0 || start[pStart] < end[pEnd]) {
            room++;
        } else {
            pEnd++;
        }
        pStart++;
    }
    return room;
}


int *findAnagrams(char *s, char *sub) {
    int len_sub = strlen(sub);
    int len_s = strlen(s);

    //init hash by go throught sub
    hash[256];

    int left = 0;
    int right = 0;
    int count = 0;
    //for(int i = 0; i < len_s; i++) {
    while(right < len_s) {
        if(hash[s[right++]]-- >= 1) {
            count++;
        }
        if(count == len_s) {
            res[i++] = left;
        }
        if(right - left == len_sub  && hash[s[left++]]++ >= 0) {
            count--;
        }
    }
}

int main(void) {
    //char *s = "xabcy";
    //char *sub = "acpb";
    //bool res = check_inclusion_e(s, sub);
    //printf("%d\n", res);
    //fun(5);
    int nums[] = {3, -2, 4, 5, 6};
    int res = max_sum(nums, 5);
    printf("%d\n", res);

    return 0;
}