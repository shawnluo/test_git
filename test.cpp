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
    ...
}

int dp_16(vector<int> nums, int S) {
    // left + right = sum;
    // left - right = target;
    // left = (sum + target) / 2;

    int sum = 0;
    for(int i = 0; i < nums.size(); i++) sum += nums[i];

    if(abs(S) > sum) return 0;
    if((S + sum ) % 2) return 0;

    int BAG = (sum + S) / 2;
    vector<int> dp;
    dp[0] = 1;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = BAG; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[BAG];
}

int dp_18(vector<int> weight, vector<int> value, int BAG) {
    for(int i = 0; i < weight.size(); i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j >= weight[i]) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
    return dp[BAG];
}

for(int i = 0) {
    for(int j = ) {
        dp[j] += dp[j - coins[i]];
    }
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

int combinationSum4() {
    dp[0] = 1;
    for(int i = 0; i <= target; i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(i - nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}

int dp_23() {
    if(dp[j - coins[i]] != INT_MAX)
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
}

int dp_24()
    dp[j] = min(dp[j], dp[i - j * j] + 1);

int dp_29() {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
}

int dp_31_32() {
    dp[i][0] = max(-price[i], dp[i - 1][0] + dp[i - 1][1]);
    dp[i][1] = max(dp[i - 1][1], price[i] + dp[i - 1][0]);
}

int dp_41() {
    for() {
        for() {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }
}

int dp_42() {
    for() {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        res = max(res, dp[i]);
    }
}

int dp_43() {
    for() {
        for() {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
}

int dp_44_45() {
    for() {
        for() {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int dp_46() {
    for() {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }
    res = max(res, dp[i]);
}

int dp_47() {
    for() {
        for() {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i][j - 1]
            }
        }
    }
}

int getNext() {
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int kmp() {
    getNext(...);
    for(int i = 0; i...) {
        while() {

        }
        if() {
            j++;
        }
        if(j == t.size()) 
            return i - t.size() + 1;
    }
    return -1;
}

int dp_48() {
    for(int i = 1;) {
        for(int j = 1) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int dp_49() {
    for(int i = 1; ) {
        for(int j = 1;) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1), dp[i][j - 1] + 1;
            }
        }
    }
}

int dp_50() {
    for(int i = 1;) {
        for(int j = 1;) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }
}

int dp_52() {
    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i; j < s.size(); j++) {
            if(s[i] == t[j]) {
                if(j - i <= 1) {
                    dp[i][j] = true;
                    res++;
                } else if(dp[i + 1][j - 1] == true) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
    }
}

int dp_53() {
    for(int i = s.size() - 1;) {
        for(int j = i; ) {
            if(s[i] = t[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main(void) {
    vector<int> nums = {-1, 1, 2, 4, 3, 2};
    cout << longestIncreasingSecSubstring(nums) << endl;

    return 0;
}