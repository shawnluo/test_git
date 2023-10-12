#include "test.hpp"


void* memoryCpy(void* dst, const void* src, size_t size) {
    if(!dst || !src) return dst;

    if(src < dst) {
        char* cdst = (char*)dst;
        const char* src = (const char*)dst;

        while(size--) {
            *dst++ = *src++;
        }
    } else {
        char* lastcdst = (char*) dst + size - 1;
        const char* lastcsrc = (const char*) src + size - 1;
        while(size--) {
            *lastcdst-- = *lastcsrc--;
        }
    }
    return dst;
}

int readFile(char* buf, int n) {
    int readChar = 4;
    int copiedChar = 0;
    char buf4[4] = {0};

    while(readChar == 4 && copiedChar < n) {
        readChar = read4(buf4);
        for(int i = 0; i < readChar; i++) {
            if(copiedChar == n) {
                return copiedChar;
            }
            buf[copiedChar++] = buf4[i];
        }
    }
    return copiedChar;
}

int partition(int* nums, int start, int end) {
    int j = start - 1;
    for(int i = start; i < end; i++) {
        if(nums[start] < nums[end]) {
            swap(nums[i], nums[j++]);
        }
    }
    swap(nums[j++], nums[i]);
    return j;
}

int findKth(int* nums, int start, int end, int k) {
    if(start < end) {
        int pivot = partition(nums, start, end);
        if(pivot == k) return nums[pivot];
        else if(k < pivot) findKth(nums, start, pivot - 1);
        else findKth(nums, pivot + 1, end);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    priorit_queue<int> heap;
    for(auto it : nums) {
        heap.push(-num);
        if(heap.size() > k) {
            heap.pop();
        }
    }
    return -heap.top();
}

int breakInt(int n) {
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
        }
    }
    return dp[n];
}

int dp_11(vector<int> weight, vector<int> value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int> (BAG + 1, 0));
    // dp[i][j]
    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 0; i < weight.size(); i++ ) {
        for(int j = 0; j <= BAG; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[weight.size() - 1][BAG];
}

int dp_12(weight, value, BAG) {
    for(int i = 0; i < weight.size(); i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

bool dp_13(vector<int> nums) {
    for(auto it : nums) {
        sum += it;
    }
    if (sum % 2) return false;
}

uint64_t myPow(int base, int n) {
    if(base == 0) return 0;
    if(n == 0) return base;

    if(n < 0) {
        base = 1 / base;
        n = -n;
    }

    uint64_t res = 1.0;
    for(int i = 1; i <= n; i++) {
        res *= base;
    }
    return res;
}

int longestPalindrome(string s) {
    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++) {
        hash[s[0]]++;
    }
    int even = 0;
    int odd = 0;
    for(int i = 0; i < 256; i++) {
        even += hash[i] / 2 * 2;
        odd += hash[i] % 2;
    }
    odd = odd > 0 ? 1 : 0;
    return even + odd;
}

int dp_52(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(2, false));
    for(int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
    }

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i; j < s.size(); j++) {
            if(s[i] == s[j] && dp[i + 1][j - 1] == true) {
                res = max(res, j - i + 1);
                dp[i][j] = true;
            }
        }
    }
    return res;
}

int main(void) {
    vector<int> nums = {-1, 1, 2, 4, 3, 2};
    cout << longestIncreasingSecSubstring(nums) << endl;

    return 0;
}