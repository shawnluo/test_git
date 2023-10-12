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

int arr_02(vector<int> nums, int target) {
    int mid;
    int left = 0; 
    int right = nums.size() - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if(target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int arr_03(vector<int> nums, int val) {
    int k = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    nums.resize(k);
    return k;
}

void sinkIsland(vector<vector<int>> grid, int i, int j, int row, int col) {
    if(i < 0|| i >= row) return;
    if(j < 0|| i >= col) return;

    if(grid[i][j] == 0) return;

    grid[i][j] = '0';
    sinkIsland(grid, i + 1, j, row, col);
    sinkIsland(grid, i - 1, j, row, col);
    sinkIsland(grid, i, j + 1, row, col);
    sinkIsland(grid, i, j - 1, row, col);
}

int findIslands(vector<vector<int>> grid) {
    int row = grid.size();
    int col = grid[0].size();

    int count = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(gird[i][j] == '1') {
                sinkIsland(gird, i, j, row, col);
                count++;
            }
        }
    }
    return count;
}

long long myAtoi(string s) {
    int i = 0;
    long long res = 0, val = 0;

    while(s[i] == ' ') {
        i++;
    }
    if(s[i] == '+' || s[i] == '-') {
        if(s[i] == '-') {
            isNegative = ' ';
            i++;
        }
    }
    while(i < s.size()) {
        val = s[i] - '0';
        if(val < 0 || code > 9) {
            continue;
        }
        res *= 10;
        res += val;
        i++;
    }
    if(isNegative) {
        res = -res;
    }
    return max(min(res, INT_MAX), INT_MIN);
}

int arr_04(vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;
    int pos = right;
    vector<int> newNums(nums.size());

    while(left <= right) {
        int powL = pow(nums[left], 2);
        int powR = pow(nums[right], 2);
        if(powL > powR) {
            newNums[pos--] = powL;
            left++;
        } else {
            newNums[pos--] = powR;
            right--;
        }
    }
    return newNums;
}

int arr_05(vector<int> nums, int s) {
    int i = 0; // left
    for(int j = 0; j < nums.size(); j++) {
        sum += nums[j];
        while(sum >= s) {
            len = j - i + 1;
            res = max(res, len);
            sum -= nums[i++];
        }
    }
    return res == INT_MAX ? 0 : res;
}

int arr_06(int n) {
    int startX = 0;
    int startY = 0;
    int offset = 0;
    int half = n / 2;
    int count = 1;

    while(half--) {
        int x = startX;
        int y = startY;
        for(; y < n - offset; y++) {
            res[x][y] = count++;
        }
        for(; x < n - offset; x++) {
            res[x][y] = count++;
        }
        for(; y > startY; y--) {
            res[x][y] = count++;
        }
        for(; x > startX; x--) {
            res[x][y] = count++;
        }
        startX++;
        startY++;
        offset++;
    }
    if(n % 2) {
        res[half][half] = count++;
    }
}

// stack_02
stack<int> stIn;
stack<int> stOut;

void push (int val) {
    stIn.push(val);
}

int pop() {
    if(stOut.empty()) {
        while(!stIn.empty()) {
            stOut.push(stIn.top());
            stIn.pop();
        }
    }
}

// stack_03
queue<int> que1;
queue<int> que1;

void push(int x) {
    que1.push(x);
}

int pop() {
    int size = que1.size();
    size--;
    while(size--) {
        que2.push(que1.front());
        que1.pop();
    }
    int res = que1.front();
    que1.pop();
    que1 = que2;
    while(!que1.empty()) {
        que2.pop();
    }
    return res;
}

string rmD(string s) {
    string res;
    for(auto it : s) {
        if(res.empty() || res.back() != it) {
            res.push_back(it);
        } else {
            res.pop_back();
        }
    }
    return res;
}

void removeExtraSpaces(string s) {
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            if(j != 0) {
                s[j++] = ' ';
            }
        }
        while(i < s.size() && s[i] != ' ') {
            s[j++] = s[i++];
        }
    }
    s.resize(j);
}

void move(char x, char y) {
    cout << x << " -> " << y << endl;
}

void hanoi(int n, char a, char b, char c) {
    if(n == 1) {
        move(a, c);
    } else {
        hanoi(n - 1, a, c, b);
        move(a, c);
        hanoid(n - 1, b, a, c);
    }
}

//TODO
// 1. 字符串转成整数 myAtoi
// 2. 用栈来实现队列
// 3. 去掉string中的多余空格
// 4. hanoi

int main(void) {
    vector<int> nums = {-1, 1, 2, 4, 3, 2};
    cout << longestIncreasingSecSubstring(nums) << endl;

    return 0;
}