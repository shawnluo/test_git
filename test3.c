#include "common.h"
#include "test.h"


void findAnagrams(const char *s1, const char *s2) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int hash[256] = {0};
    int left = 0, right = 0;

    for(int i = 0; i < size2; i++) {
        hash[s2[i]]++;
    }
    int count = size2;
    while(right < size1) {
        if(hash[s1[right++]]-- >= 1) {
            count--;
        }
        if(count == 0) {
            printf("%d\n", left);
        }
        if(right - left == size2) {
            if(hash[s1[left++]]++ >= 0) {
                count++;
            }
        }
    }
}

//TODO 1
void findAnagrams_1(const char *s1, const char *s2) {

}

//TODO 2
int longest_increasing_subsequence(const int nums[], int len) {
    int i, j;
    int dp[len];

    dp[]

    for(i = 1; i < size; i++) {
        for(j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}

int main(void) {
    findAnagrams("xabtbay", "ab");

    return 0;
}