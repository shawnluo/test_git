#include "test.hpp"


// TODO: dp

// 0.                            - 01背包
    // 1. 二维数组
    // 2. 一维滚动数组 - 也就是把二维数组数据压缩到只有一行。重复使用这一行数据(就是carl所说的拷贝)：
            // 1. 从上次的数据取值，将本次计算后的值，覆盖掉本行。因为二维数组的行列矩阵数据只被斜下部的单元使用。
            // 2. j需要倒序。因为根据dp[j] = dp[j - weight[i]] + value，dp[j]是一维的，其取值是根据左边的数据来获取的。
                // 如果从左边开始循环，那么左边的取值会被不断重复计入。从而影响结果。
                // 如果从右边开始循环，因为左边的元素都是初始值0。其不会影响计算结果！
                // 对比二维数组，其数据都是独立存在的，没有被重复使用。

// 1. 装满背包的最大价值是多少？    - 纯完全背包
// 2. 装满背包有多少种方法？求组合  - 零钱兑换2
// 3. 装满背包有多少种方法？求排列  - 组合总和4
// 4. 装满背包最少用多少个物品？    - 322零钱兑换

// 5. 最长连续上升子序列
    // 1）. 长度
    // 2）. 打印出上升子序列

// 6. 最长上升子序列
    // 1）. 长度
    // 2）. 打印出上升子序列

// 7. 排序后的单元的序列长度
    // 1). 双指针去重
    // 2). 判断与前一个数不相等
    // 3). 除重后的长度 - dp解
    // 4). 打印除重后的序列 - unordered_set

// 8. 未排序后的单元的序列长度
    // 1）. 除重后的长度
        // 1. dp
        // 2. while loop delete
    // 2）. 打印除重后的序列

// 9. leetcode 1091 - the shortest path in binary matrix
    // 1. BFS - breadth-first search

// 24 完全平方数
// dp[j] = min(dp[j], dp[j - i * i] + 1)

void test() {
    vector<int> nums{-1, 1, 1, 2, 2, 2, 3, 3};

    int low = 0;
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] != nums[i + 1]) {
            nums[low++] = nums[i];
        }
    }
    nums[low] = nums.back();
    cout << nums.back() << endl;

    for(int i = 0; i <= low; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    // aabaaf
    static void getNext(int* next, const string& s) {
        next[0] = 0;
        int j = 0;
        for(int i = 1; i < s.size(); i++) {
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];    // 
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        // for(int i = 0; i < s.size(); i++) {
        //     cout << next[i] << " ";
        // }
        // cout << endl;
    }

    static int myStrstr(string s, string t, int *next) {
        int j = 0;
        getNext(next, t);
        for(int i = 0; i < s.size(); i++) {
            while(j > 0 && s[i] != t[j]) {
                j = next[j - 1];
            }
            if(s[i] == t[j]) {
                j++;
            }
            if(j == t.size()) {
                return i - t.size() + 1;
            }
        }
        return -1;
    }
};

// dp 2
// fib[i] = fib[i - 1] + fib[i - 2]
int fib(int n) {
    if(n <= 1) return n;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// mat rotate
void showMe(const vector<vector<int>> mat) {
    for (auto x : mat) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

void mat_rotate(vector<vector<int>>& mat) {
    int size = mat[0].size();
    // int layers = 0;
    for(int i = 0; i < size / 2; i++) {
        for(int j = i; j < size - 1 - i; j++) {
            int tmp = mat[i][j];
            mat[i][j] = mat[j][size - i - 1];
            mat[j][size - i - 1] = mat[size - 1 - i][size - 1 - j];
            mat[size - 1 - i][size - 1 - j] = mat[size - 1 - j][i];
            mat[size - 1 - j][i] = tmp;
        }
    }
}

// mat spiral
void mat_spiral(int n) {
    int N = n / 2;
    int startX = 0;
    int startY = 0;
    int offset = 0;
    int count = 0;
    vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));

    while(N-- > 0) {
        int x = startX;
        int y = startY;
        for(; x < n - offset; x++) {
            res[x][y] = count++;
        }
        for(; y < n - offset; y++) {
            res[x][y] = count++;
        }
        for(; x > startX; x--) {
            res[x][y] = count++;
        }
        for(; y > startY; y--) {
            res[x][y] = count++;
        }
        startX++;
        startY++;
        offset++;
    }
    showMe(res);
}

// is rectangle from given points(x, y)
bool isRectangle(int (*nums)[2], int len) {
    // calculate the length
    // point0: nums[0][0], nums[0][1]
    // ...
    // point3: nums[3][0], nums[3][1]
    int len1 = nums[1][0] - nums[1][1];
    // sorting 
    // if 2 same longest, 2 mid, 2 short: longest * longest = mid * mid + short * short, then yes, else no

    vector<int> res{1, 7, 9, 0, -1};
    sort(res.begin(), res.end());
    return true;
}

// read API is given, readFour(), implement a read function to read the whole file
int read(char *buf, int n) {
    int copiedChars = 0;
    int readChars = 4;
    char buf4[4];

    while(copiedChars < n && readChars == 4) {
        readChars = read4(buf4);

        for(int i = 0; i < readChars; i++) {
            if(copiedChars == n) {
                return copiedChars;
            }
            buf[copiedChars] = buf4[i];
            copiedChars++;
        }
    }
    return copiedChars;
}






int main(void) {

    return 0;
}