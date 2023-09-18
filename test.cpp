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
// Done

// reverse linked list
typedef struct node {
    int data;
    struct node *next;
} Node, *pNode;

#define LEN sizeof(Node)

void printLL(pNode pHead) {
    while(pHead) {
        cout << pHead->data << endl;
        pHead = pHead->next;
    }
}

void createNode(pNode *ppHead) {
    int nums[] = {1, 2, 3, 4, 5};
    if(*ppHead == nullptr) {
        *ppHead = (pNode)malloc(LEN);
    }
    (*ppHead)->data = nums[0];
    pNode pNow = *ppHead;
    pNode pNext = *ppHead;

    for(int i = 1; i < sizeof(nums) / sizeof(nums[0]); i++) {
        pNext = (pNode)malloc(LEN);
        pNext->data = nums[i];
        pNow->next = pNext;
        pNow = pNext;
    }
}

pNode reverseLL(pNode pHead) {
    if(pHead == nullptr) {
        return nullptr;
    }
    pNode pCur = pHead;
    pNode pPre = nullptr;
    pNode pNext;

    while(pCur) {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    return pPre;
}

// malloc aligned memory
void *memAlign(size_t size, size_t alignment) {
    // 1. the new length
    int offset = alignment - 1;
    int newSize = size + offset + sizeof(size_t);
    // 2. malloc
    size_t *addr = (size_t *)malloc(newSize);
    // 3. the newAddr
    void *newAddr = (void *)((size_t)(addr + offset) & ~(offset));

    // 4. save the diffencial
    *(size_t *)(newAddr - 1) = (size_t *)newAddr - addr;

    return newAddr;
}

void align_free(void * aligned_addr) {
    void *addr = (size_t *)aligned_addr - *((size_t *)aligned_addr - 1);
    free(addr);
}

// binary tree
struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;

    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

    // 0. create
treeNode* insertTree(treeNode* root, int value) {
    if(root == nullptr) {
        // cout << "11" << endl;
        return new treeNode(value);
    }

    if(value < root->val) {
        root->left = insertTree(root->left, value);
    } else if(value > root->val) {
        root->right = insertTree(root->right, value);
    }

    return root;
}

void insert2(treeNode** root, int val) {
    if(*root == nullptr) {
        *root = new treeNode(val);
    }
    if(val < (*root)->val) {
        insert2(&((*root)->left), val);
    } else if(val > (*root)->val) {
        insert2(&((*root)->right), val);
    }
}

    // 1. travel
void travelTree(treeNode* root) {
    if(root == nullptr) {
        // cout << "empty" << endl;
        return;
    }
    // cout << root->val << endl;
    travelTree(root->left);
    // cout << root->val << endl;
    travelTree(root->right);
    cout << root->val << endl;
}

    // 2. reverse
treeNode* reverse(treeNode* root) {
    if(root == nullptr) {
        return root;
    }
    swap(root->left, root->right);

    reverse(root->left);
    reverse(root->right);

    return root;
}
    // 3. search - simple
bool search(treeNode* root, int val) {
    if(root == nullptr) {
        return false;
    }
    if(root->val == val) {
        return true;
    }

    if(val < root->val)
        search(root->left, val);
    else
        search(root->right, val);

    return false;
}

// my power
float myPow(float base, int num) {
    if(base == 0) return 0;
    if(num == 0) return 1;
    if(num == 1) return base;

    if(num < 0) {
        base = 1 / base;
        num = -num;
    }

    float res = 1.0 * base;
    // base = (float)base;
    for(int i = 2; i <= num; i++) {
        res = res * base;
    }
    return res;
}

// reverse string: show me -> wohs em
void reverse(string& s, int start, int end) {
    if(s.size() <= 1) {
        return;
    }
    if(start < 0) start = 0;
    if(end >= s.size()) end = s.size() - 1;

    while(start < end) {
        swap(s[start], s[end]);
        start++, end--;
    }
}

void removeExtraSpaces(string& s) {
    // 1. clear infront spaces
    int index = 0;
    int slow = 0;
    while(s[index] == ' ') {
        index++;
    }
    // 2. remove mid
    if(index == s.size() - 1) {
        return;
    }
    // while(index < s.size() && ) {

    // }
    for(int i = index + 1; i < s.size(); i++) {
        if(s[i] == s[i - 1] && s[i] == ' ') {

        } else {
            s[slow++] = s[i];
        }
    }

    // 3. remove rear spaces

}

void removeSpaces(string& s) {
    int slow = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            if(slow != 0) {
                s[slow++] = ' ';
            }
            while(i < s.size() && s[i] != ' ') {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

void sinkIsland(vector<vector<int>>& mat, int x, int y, int row, int col) {
    // deal with border border
    if(x < 0 || x >= row) {
        return;
    }
    if(y < 0 || y >= col) {
        return;
    }
    if(mat[x][y] == 0) {
        return; 
    }

    mat[x][y] = 0;
    sinkIsland(mat, x + 1, y, row, col);
    sinkIsland(mat, x - 1, y, row, col);
    sinkIsland(mat, x, y + 1, row, col);
    sinkIsland(mat, x, y - 1, row, col);
}

// count island
// int countIsland() {
//     for() {
//         for() {
//             if(mat[i][j] == 1) {
//                 sinkIsland(mat, i, j, row, col);
//                 count++;
//             }
//         }
//     }
// }

// dp3
int dp_3(int n) {
    vector<int> dp(n + 1, 0);
    if(n <= 2) {
        return n;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// dp4
int dp_4(vector<int> cost) {
    vector<int> dp(cost.size() + 1, 0);
    dp[0] = 0;
    dp[1] = 0;

    for(int i = 2; i <= cost.size(); i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
}

// bt_2: 返回[1, n]中所有可能的k个数的组合
vector<vector<int>> res;
vector<int> buf;
void bt_2(int n, int k, int pos) {
    if(buf.size() == k) {
        res.push_back(buf);
        return;
    }
    for(int i = pos; i <= n; i++) {
        buf.push_back(i);
        bt_2(n, k, i + 1);
        buf.pop_back();
    }
}


// bt_15
// backTracking: permutation of "abcd"
void bt_15(string s, int pos) {
    if(pos == s.size()) {
        cout << s << endl;
    }
    for(int i = pos; i < s.size(); i++) {
        swap(s[i], s[pos]);
        bt_15(s, i + 1);
        swap(s[i], s[pos]);
    }
}


// 000 123 0 123 456 
// abc abc x abc abc xy
void tmpNext(int *next, string s, string t) {
    next[0] = 0;
    int j = 0;

    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != t[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

// dp 11 0-1 snapsack
int dp_11(vector<int> weight, vector<int> value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int>(BAG + 1, 0));
    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }
    for(int i = 1; i < weight.size(); i++) {
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

// dp 12 0-1 rolling array
int dp_12(vector<int> weight, vector<int> value, int BAG) {
    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}
// dp 13


// dp 18 repeatable
int dp_18(vector<int> weight, vector<int> value, int BAG) {
    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = weight[i]; j <= BAG; j++) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

// dp 19 coin change
int dp_19(vector<int> coins, int BAG) {
    // dp[j]: 凑成j的组合数
    vector<int> dp(BAG + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= coins[i]; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[BAG];
}

// dp 21
int dp_21(vector<int> nums, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;  // make up 0, has 1 way
    // make up i, has dp[i] ways
    // dp[i] += dp[i - nums[j]]

    // // dp[j]: makeup j, need minimal dp[j] coins
    // // dp[j] = min(dp[j], dp[j - nums[i]] + 1);

    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(i >= nums[j]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[amount];
}

// dp 22
int dp_22(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // dp[1] = 0;

    for(int i = 1; i <= n; i++) {       //遍历背包
        for(int j = 1; j <= m; j++) {   //遍历物品
            if(i >= j) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

// dp 23
int dp_23(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            if(j - coins[i] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    if(dp[amount] == INT_MAX) {
        return -1;
    }
    return dp[amount];
}

// dp 24: 给定一个整数n, 返回和为n的完全平方数的最少数量
int dp_24(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i * i; j <= n; j++) {
            // if(j - i * i != INT_MAX) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            // }
        }
    }
    if(dp[n] == INT_MAX) {
        return -1;
    }
    return dp[n];
}

// dp 26
bool dp_26(string s, vector<string> wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for(int i = 1; i <= s.size(); i++) {    // 遍历背包
        for(int j = 0; j < i; j++) {        // 遍历物品
            string word = s.substr(j, i - j);
            if(wordSet.find(word) != wordSet.end() && dp[j]) {
                dp[i] = true;
            }
        }
    }
    return dp[s.size()];
}

// dp 29
int dp_29(vector<int> nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
}

// dp 32
int dp_32(vector<int> prices) {
    vector<vector<int>> dp(prices.size(), vector<int> (2, 0));
    // dp[i][0]: have stock
    // dp[i][1]: have no stock
    dp[0][0] = -prices[0];  // 
    dp[0][1] = 0;

    for(int i = 1; i < prices.size(); i++) {
        // 昨天已经有股票了: dp[i - 1][0]
        // 昨天没有股票，今天买股票, : dp[i][1] - prices[i]
        dp[i][0] = max(dp[i - 1][0], -prices[i]);

        // 昨天没有股票: dp[i - 1][1]
        // 今天没有股票: dp[i - 1][0] + price[i]
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[prices.size() - 1][1];
}

// dp 34
int dp_34(vector<int> prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[prices.size() - 1][1];
}

// dp 39
int dp_39(vector<int> prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
}

// dp 41
/*
    思路： dp[0] = 1. 不能用一个for循环来判断没有排序过得序列。比如 7, 8, 2, 3.  如果只判断当前数和前一个数，
    那么结果就会是 8 > 7，dp[1] = 2, 3 > 2, dp[3] = 3。这明显是错误的。
    正确的思路应该是for循环选定一个数时，从[0, i)比较其之前的所有数。
*/
int dp_41(vector<int> nums) {
    vector<int> dp(nums.size() + 1, 1);
    dp[0] = 1;
    int res = 0;
    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[i - 1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }
    return res;
}

// dp 41_1
/*
    ds
*/

// dp 42
/*
    思路：一个for loop. 如果nums[i] > nums[i - 1], dp[i] = dp[i - 1] + 1; 取最大的dp[i]
*/
int dp_42(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    dp[0] = 1;
    int res = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        res = max(res, dp[i]);
    }
    return res;
}

// dp 43
/*
    连续
*/
int dp_43(vector<int> nums1, vector<int> nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int res = 0;

    for(int i = 1; i <= nums1.size(); i++) {
        for(int j = 1; j <= nums2.size(); j++) {
            if(nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

// dp 44
/*
    非连续
*/
int dp_44(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    
    for(int i = 1; i < s1.size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

// dp 45
/*
    公共子序列
*/
int dp_45(vector<int> nums1, vector<int> nums2) {
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
    for(int i = 1; i < nums1.size(); i++) {
        for(int j = 1; j < nums2.size(); j++) {
            if(nums1[i] == nums2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[nums1.size()][nums2.size()];
}

// dp 46
/*
    最大子序和:
    dp[i]: end with element i, the max sum
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    res = max(res, dp[i]);
*/
int dp_46(vector<int> nums) {
    vector<int> dp(nums.size(), INT_MIN);
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}

// dp 47
bool dp_47(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[s.size()][t.size()] == t.size() ? true : false;
}

// dp 48
/*
    string s and string t, 求在s的子序列中，t出现的个数
    dp[i][j]: 以i - 1为结尾的s子序列中，出现以j - 1为结尾的个数
    if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
*/
int dp_48(string s, string t) {
    return 0;
}

// dp 49
/*
    两个字符串的删除操作：找到使得s和t相同，所需的最小步数。每步可以删除任意一个字符串
    dp[i][j]: 以i - 1为结尾的s，和以j - 1为结尾的t, 想要达到相等，所需要删除元素的最少次数
*/
int dp_49(string s1, string s2) {
    vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 0; i <= s1.size(); i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= s2.size(); j++) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

// dp 50
/*
    编辑距离：将s装换成t，所需要的最少操作数
*/
int dp_50(string s1, string s2) {
    vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for(int i = 0; i <= s1.size(); i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= s2.size(); j++) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

// dp 52
// 回文子串:
// from the last char, back to first one.
// dp[i][j]: 从[i, j], 多少个回文子串
int dp_52(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for(int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
    }
    int res = 0;

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i; j < s.size(); j++) {
            if(s[i] == s[j]) {
                if(j - i <= 1) {
                    res++;
                    dp[i][j] = true;
                } else if(dp[i + 1][j - 1] == true) {
                    res++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp[0][s.size() - 1];
}

// dp 53
// 最长回文子序列
int dp_53(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i + 1; j < s.size(); j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.size() - 1];
}

// rotate mat
void rotateMat(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();

    for(int i = 0; i < row / 2; i++) {
        for(int j = i; j < col - i - 1; j++) {
            int save = mat[i][j];
            // [l, R) - top
            mat[i][j] = mat[j][row - i - 1];
            // [U, D) - right
            mat[j][row - i - 1] = mat[row - i - 1][row - j - 1];
            // [R, L) - bottom
            mat[row - i - 1][row - j - 1] = mat[row - j - 1][i];
            // [D, U) - left
            mat[row - j - 1][i] = save;
        }
    }
}

// spiral mat
void spiralMat(int n, vector<vector<int>>& mat) {
    int half = n / 2;
    int startX = 0;
    int startY = 0;
    int count = 1;
    int offset = 1;
    
    while(half--) {
        int x = startX;
        int y = startY;
        

        for( ; y < n - offset; y++) {
            mat[x][y] = count++;
        }
        for( ; x < n - offset; x++) {
            mat[x][y] = count++;
        }
        for( ; y > startY; y--) {
            mat[x][y] = count++;
        }
        for( ; x > startX; x--) {
            mat[x][y] = count++;
        }
        startX++;
        startY++;
        offset++;
    }

    if(n % 2) {
        mat[half][half] = count;
    }

    // for(auto x : mat) {
    //     for(auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

// meeting room

/*
    write the body of the is_overlapp function below:
    // A. time interval is defined as
    typdef struct {
        unit32_t start; // Time stamp of the interval start point (inclusive)
        uint32_t stop;  // Time stamp of the interval end point (inclusive)
    } time_interval_t;

    // intervals[] - an array of time intervals sorted by the 'start' field, followed by the 'stop' field.
    // 
    // count - number of elements in intervals
    // new_interval - a new time interval to be tested
    //
    // returns - true if new_interval overlaps in time with any interval in the intervals array, false other

    int comp(void **x, void **y) {
        int *a = (int **)x;
        int *b = (int **)y;
        
        if(a[0] == b[0]) {
            return a[1] - b[1];
        }

        return a[0] - b[0];
    }

    bool is_overlapp(time_interval_t intervals, uint32_t count, time_interval_t new_interval) {
        // 1. sort intervals
        qsort(intervals, count, sizeof(uint32_t), comp);
        // 2. if new_interval[0][1] < first[0], return false
        // 3. if new_interval[size - 1][0] > last[1], return false
        // 4. if new_interval[0] >= intervals[i][1] && new_interval[1] <= intervals[i + 1][0] return false
        // 5. return true;
    }
*/

int main(void) {
#if 0
    // string s = "aabaabaaf";
    // string t = "aabaaf";
    // int next[5] = {0};
    // getNext(next, t);
    // cout << Solution::myStrstr(s, t, next) << endl;

    // vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // mat_rotate(mat);
    // showMe(mat);

    // mat_spiral(4);

    // pNode pHead = nullptr;
    // createNode(&pHead);

    // pHead = reverseLL(pHead);
    // printLL(pHead);

    // treeNode* root = nullptr;
    // insert2(&root, 1);
    // insert2(&root, 2);
    // insert2(&root, 3);
    // travelTree(root);

    // cout << myPow(-2, -1) << endl;

    // string s = "abcd";
    // reverse(s, 1, 4);
    // s.resize(2);
    // cout << s << endl;

    // string s = "abc";
    // bt_15(s, 0);

    // bt_2(4, 2, 0);
    // for(auto x : res) {
    //     for(auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
#endif
    // vector<int> weight = {1, 3, 5};
    // vector<int> value = {50, 20, 8};
    // int BAG = 3;

    // cout << dp_18(weight, value, BAG) << endl;

    // string s1 = "ab";
    // string s2 = "ac";
    // cout << dp_49(s1, s2) << endl;

    // string s = "abacd";
    // cout << dp_53(s) << endl;

    // vector<vector<int>> mat = {{1, 2, 3}, 
    //                             {4, 5, 6},
    //                             {7, 8, 9}};
    // rotateMat(mat);

    int n = 5;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1));
    spiralMat(n, mat);

    for(auto x : mat) {
        for(auto y : x) {
            // cout << y << " ";
        }
        // cout << endl;
    }

    return 0;
}

