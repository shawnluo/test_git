#include "test.hpp"


// ----------------------- 数组 1.1
// 1, 3, 5, 9   t = 9

int search(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;

    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int do_search(vector<int> nums, int start, int end, int target) {
    if(start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if(nums[mid] == target) {
        return mid;
    }
    if(target < nums[mid]) {
        return do_search(nums, start, mid - 1, target);
    } else {
        return do_search(nums, mid + 1, end, target);
    }
}

int searchRe(vector<int> nums, int target) {
    return do_search(nums, 0, nums.size() - 1, target);
}

// ----------------------- 1.2
// 1, 1, 2, 4, 6, 9 ,1    val = 1
int remove(vector<int> nums, int val) {
    int len = nums.size();
    int index = 0;

    for(int i = 0; i < len; i++) {
        if(nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

// ----------------------- 1.3
vector<int> square(const vector<int> nums) {
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    int newSize = right;
    vector<int> res(size);

    while(left < right) {
        if(nums[left] * nums[left] > nums[right] * nums[right]) {
            res[--newSize] = nums[left] * nums[left];
            left++;
        } else {
            res[-- newSize] = nums[right] * nums[right];
            right--;
        }
    }
    return res;
}

// ----------------------- 1.4
int minSize(vector<int> nums, int s) {
    int left = 0;
    int right = 0;
    int size = nums.size();
    int sum = 0;
    int res = INT_MAX;
    while(right < size) {
        sum += nums[right];
        while(sum >= s) {
            sum -= nums[left];
            left++;
            res = min(res, sum);
        }
        right++;
    }
    if(res == INT_MAX) return 0;

    return res;
}

// ----------------------- 1.5
// TODO
vector<vector<int>> mat(int n) {
    int offset = 1;
    int startX = 0;
    int startY = 0;
    int index = 0;
    int round = n / 2;
    vector<vector<int>> res(n, vector<int>(n, 0));   //?
    vector<vector<int>> res(n, vector<int>(n, 0));
    while(round > 0) {
        int x = startX;
        int y = startY;
        for(; y < n - offset; y++) {
            res[x][y] = index++;
        }
        for(; x < n - offset; x++) {
            res[x][y] = index++;
        }
        for(; y > startY; y--) {
            res[x][y] = index++;
        }
        for(; x > startX; x--) {
            res[x][y] = index++;
        }
        startX++;
        startY++;
        offset++;
        round--;
    }
    if(n % 2) {
        res[n / 2][n / 2] = index;
    }
    return res;
}

// ----------------------- 链表 2.2
void delVal(pNode *ppHead, int val) {
    pNode *pp = ppHead;
    while(*pp) {
        if((*pp)->val != val) {
            pp = (*pp)->next;
        } else {
            pNode tmp = *pp;
            *pp = (*pp)->next;
            delete tmp;
        }
    }
}

// ----------------------- 2.3
int getLL(pNode pHead, int index) {
    if(!pHead) {
        return -1;
    }
    pNode p = pHead;
    int i = 0;
    while(p && i != index) {
        p = p->next;
    }
    if(p) {
        return p->val;
    }
    return -1;
}

void addAtHead(pNode* ppHead, int val) {
    pNode *pp = ppHead;
    pNode pNew = new Node(val);
    pNew->next = *ppHead;
    *pp = pNew;
}

void addAtTail(pNode pHead, int val) {
    pNode p = pHead;
    while(p->next != nullptr) {
        p = p->next;
    }
    pNode pNew = new Node(vak);
    p->next = pNew;
}

void deleteAtIndex(pNode* ppHead, int index) {
    if(!*ppHead) {
        return;
    }
    pNode *pp = ppHead;
    int i = 0;
    while(*pp && i != index) {
        pp = &(*pp)->next;
    }
    if(*pp) {
        pNode tmp = *pp;
        *pp = (*pp)->next;
        delete tmp;
    }
}

// ----------------------- 2.4
pNode reverse(pNode& pHead) {
    pNode pCur = pHead;
    pNode pPre = pHead;
    pNode pNex = nullptr;

    while(pCur) {
        pNex = pCur->next;
        pCur->nex = pPre;
        pPre = pCur;
        pCur = pNex;
    }
    return pPre;
}

// ----------------------- 2.5
pNode swapPairs(pNode& pHead) {
    pNode pVHead = new Node(0);
    pVHead->next = pHead;
    pCur = pVHead;

    while(pCur->next && pCur->next->next) {
        pNode p1 = pCur->next;
        pNode p2 = pCur->next->next;
        pNode p3 = pCur->next->next->next;

        pCur->next = p2;
        p2->next = p1;
        p1->next = p3;

        pCur = pCUr->next->next;
    }
    return pVHead->next;
}

// ----------------------- 2.6
void delNth(pNode& *ppHead, int n) {
    pNode pProb = *ppHead;
    pNode *pp = ppHead;

    for(int i = 0; i < n; i++) {
        pProb = pProb->next;
    }

    while(pProb) {
        pp = &(*pp)->next;
    }
    pNode tmp = *pp;
    *pp = (*pp)->next;
    delete tmp;
}

// ----------------------- 02-07 
pNode getinterSection(pNode pHead1, pNode pHead2) {
    pNode p1 = pHead1;
    pNode p2 = pHead2;

    int size1 = 0, size2 = 0;
    while(p1 != nullptr) {
        p1 = p1->next;
        size1++;
    }
    while(p2 != nullptr) {
        p2 = p2->next;
        size2++;
    }

    p1 = pHead1;
    p2 = pHead2;
    if(size1 < size2) {
        swap(p1, p2);
        swap(size1, size2);
    }

    int diff = size2 - size1;
    while(diff--) {
        p2 = p2->next;
    }

    while(p1) {
        if(p1 == p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return nullptr;
}


int main(void) {
    vector<int> nums{1, 3, 5, 9};
    int target = 1;
    int ret = searchRe(nums, target);
    cout << ret << endl;

    return 0;
}

// ----------------------- 02-08
pNode findEntry(pNode pHead) {
    if((pHead == nullptr) || (pHead->next == nullptr)) {
        return nullptr;
    }

    pNode pFast = pHead;
    pNode pSlow = pHead;

    while(pFast) {
        pFast = pFast->next->next;
        pSlow = pFast->next;
        if(pFast == pSlow) {
            break;

        }    
    }
    if(!pFast) {
        return nullptr;
    }
    pFast = pHead;
    while(pFast != pSlow) {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    return pFast;
}

// ----------------------- 02-08
vector<vector<int>> findThree(vector<int>& nums, int val) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    int size = nums.size();
    int left = 1;
    int right = size - 1;
    int sum = 0;
    vector<int> buf;

    for(int i = 0; i < size - 2; i++) {
        // val 可能是负数，所以这里不能用 nums[i] > val来修剪. 比如[-4, -3, -2, -1], val = -10
        // if(nums[i] > val) {
        // 这是正确的方式来修枝
        if(nums[i] > val && (nums[i] >= 0 || target >= 0))
            return res;
        }

        // 去重
        if(i > 0 && nums[i - 1] == nums[i]) {   // this is the right way to get ride of repeat
            continue;
        }

        sum = 0;
        while(left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if(sum == val) {
                res.push_back(vector<int> {nums[i], nums[left], nums[right]});

                // deal with the duplicates: pass the duplicated numbers
                while(left < right && nums[right - 1] == nums[right]) {
                    right--;
                }
                while(left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                left++, right--;
            } else if(sum < val) {
                left++;
            } else {
                right--;
            }
        }

    }

    return res;
}

// ----------------------- 02-08-1
// the pairs which sum equasl val
vector<vector<int>> findTwo(vector<int> nums, int val) {
    unordered_map<int, int> num_map;
    // for(auto x : nums) {
    //     num_map[x] = 1;
    // }

    vector<vector<int>> res;
    vector<int> save;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(nums[i] + nums[j] == val) {
                
                if(num_map[nums[i]] == 0 && num_map[nums[j]] == 0) {
                    num_map[nums[i]] = 1;
                    num_map[nums[j]] == 1;
                    save.clear();
                    save.push_back(nums[i]);
                    save.push_back(nums[j]);
                    res.push_back(save);
                }
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 1, 1, 2, 4};
    vector<vector<int>> res = findTwo(nums, 8);
    vector<vector<int>> res = findThree(nums, 8);
    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

// ----------------------- 02-08-2
// 三数之和
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int k = 0; k < nums.size(); k++) {
        if(nums[k] > target && nums[k] >= 0) {
            break;
        }
        if(k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }
        for(int i = k + 1; i < nums.size(); i++) {
            if(nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                break;
            }
            if(i > k + 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[k] + nums[i] + nums[left] + nums[right];
                if(sum == target) {
                    res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                    // 去重
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++, right--;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return res;
}

// ===== 字符串
// ----------------------- 字符串 03-02
void reverseStr(char* s, int start, int len) {
    char *left = s + start;
    char *right = s + start + len - 1;

    while(left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++, right--;
    }
}

void reverseStr2(char* s, int k) {
    int size = strlen(s);
    int index = 0;
    while(index < size) {
        if((size - index) < k) {
            reverseStr(s, index, size - index);
            break;
        } else if((size - index) < 2 * k) {
            reverseStr(s, index, k);
            break;
        } else {
            reverseStr(s, index, k);
            index += 2 * k;
        }
    }
}

// using string
void reverse(string& s, int start, int end) {
    int left = start;
    int right;

    if(end <= s.size() - 1) {
        right = end;
    } else {
        right = s.size() - 1;
    }
}

int main(void) {
    string s = "abcdefghikl";
    for(int i = 0; i < s.size(); i += 200) {
        reverse(s, i, i + 100);
    }
    reverseStr(s);
    cout << s << endl;
    return 0;
}

// =================== 哈希表

// 快乐数
/*
202. Happy Number
Easy
9.3K
1.2K
company
Accenture
company
Apple
company
Amazon
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
*/
int getSum(int n) {
    int sum = 0;
    while(n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> set;

    while(1) {
        int sum = getSum(n);
        if(sum == 1) {
            return true;
        }
        if(set.find(sum) != set.end()) {
            return false;
        } else {
            set.insert(sum);
        }
        n = sum;
    }
}

// ----------------------- 字符串 04-04
/*
151. Reverse Words in a String
Medium
7.1K
4.8K
company
Amazon
company
Apple
company
Arista Networks
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

*/
class Solution {
public:
    string reverseWords(string s) {
        // 1. remove extra spaces
        removeExtraSpaces(s);

        int size = s.size();
        reverse(s, 0, size - 1);

        int start = 0;
        int i = 0;
        while(i <= size) {
            if(i == size || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
            i++;
        }
        return s;
    }

    void removeExtraSpaces(string& s) {
        int size = s.size();
        int fastIndex = 0;
        int slowIndex = 0;
        while(size > 0 && s[fastIndex] == ' ' && fastIndex < size) {
            fastIndex++;
        }

        while(fastIndex < size) {
            // fastIndex - 1 > 0 1. 是确保s[fastIndex - 1]是合法的. 2. 之前已经将第一个字符串是空格的情况排除了。
            if(fastIndex - 1 > 0 \
                && s[fastIndex - 1] == s[fastIndex] \
                && s[fastIndex] == ' ') {
                    fastIndex++;
                    continue;
            } else {
                s[slowIndex] = s[fastIndex];
                fastIndex++;
                slowIndex++;
            }
        }

        if(slowIndex > 1 && s[slowIndex - 1] == ' ') {
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex);
        }
    }

    void reverse(string& s, int start, int end) {
        int size = s.size();
        int left = start;
        int right = end;
        while(left < right) {
            swap(s[left], s[right]);
            left++, right--;
        }
    }
};

/*
516. Longest Palindromic Subsequence
Medium
8.9K
312
company
Cisco
company
Amazon
company
Goldman Sachs
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/
int s53_longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }
    int size = s.size();
    for(int i = size - 1; i >= 0; i--) {
        for(int j = i + 1; j < size; j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][size - 1];
}

// 字符串 5-左旋转字符串
string reverse3(string& s, int start, int end) {
    int left = start;
    int right = end;

    while(left < right) {
        swap(s[left++], s[right--]);
    }
    return s;
}

string rotateString3(string s, int k) {
    reverse3(s, 0, k - 1);
    reverse3(s, k, s.size() - 1);
    reverse3(s, 0, s.size() - 1);

    return s;
}

// 字符串-myStrstr - KMP算法
void findNext(int *next, char* s) {
    int j = 0;
    next[0] = j;

    for(int i = 1; i < strlen(s); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int myStrstr(char* s, char* needle, int* next) {
    int j = 0;
    for(int i = 0; i < strlen(s); i++) {
        while(j > 0 && s[i] != needle[j]) {
            j = next[j - 1];
        }
        if(s[i] == needle[j]) {
            j++;
        }
        if(j == strlen(needle)) {
            return i - strlen(needle) + 1;
        }
    }
    return -1;
}

int main(void) {
    char *s = "aabaabaaxaabaaf";
    char *needle = "aabaaf";
    int size = strlen(needle);
    int next[size];
    findNext(next, needle);

    cout << myStrstr(s, needle, next) << endl;

    return 0;
}

// 字符串- 7-重复的子字符串
// 7-1 brute force
// 判断s是否由sub重复组成？
bool isRepeatSub(string s, string sub) {
    int size = s.size();
    int j = 0;
    if(s.size() % sub.size()) {
        return false;
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != sub[j]) {
            return false;
        }
        if(++j == sub.size()) {
            j = 0;
        }
    }
    return true;
}

bool repeatString(string s) {
    int size = s.size();

    for(int i = 1; i < size; i++) {
        string sub = s.substr(0, i);
        if(isRepeat(s, sub) == true) {
            return true;
        }
    }
    return false;
}

int main(void) {
    string s = "ababab";
    string sub = "ab";

    cout << repeatString(s) << endl;

    return 0;
}

// kmp version. preffix, suffix
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size());
        getNext(s, next);

        if(next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0) {
            return true;
        }
        return false;
    }

    // aabaaf
    static void getNext(string s, vector<int>& next) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];    // 如果比较到 s[j]: a 和 s[i]: f 不相等，那么就比较j回退到以s[j-1]为结尾的，共同前后缀的字符之后的位置，继续比较, why?
                                    // TODO 因为，eg. abxaby, 在s[j]: x比较s[i]：y - 不相等。那么j应该回退到
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
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

int main(void) {
    string s = "aabaabaaf";
    string t = "aabaaf";
    int next[5] = {0};
    // getNext(next, t);
    cout << Solution::myStrstr(s, t, next) << endl; // 如果要直接调用类中的方法，需要将方法定义为static

    return 0;
}

// 动态规划

// ---------------------------- 基本题型 --------------------------------------------

// 1. 装满背包的最大价值是多少？    - 纯完全背包
// 2. 装满背包有多少种方法？求组合  - 零钱兑换2
        // dp[j] += dp[j - nums[i]]     也就是所有dp[j - nums[i]]的集合
// 3. 装满背包有多少种方法？求排列  - 组合总和4
// 4. 装满背包最少用多少个物品？    - 322零钱兑换


// ---------------------------- 详细展开 --------------------------------------------

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

int getLen(vector<int> nums) {
    int left = 0;
    int count = 0;

    while(left < nums.size()) {
        count++;
        int index = left + 1;

        while(index < nums.size() && nums[index] == nums[left]) {
            index++;
        }
        left = index;
    }
    return count; 
}

// 7.2
int getLen2(vector<int> nums) {
    int count = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            count++;
        }
    }
    return count;
}

// 7.3
int getLen3(vector<int> nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    return dp[nums.size() - 1];
}

// 7.4
int getLen4(vector<int> nums) {
    unordered_set<int> set;
    int res = 0;

    for(int i = 0; i < nums.size(); i++) {
        set.insert(nums[i]);
    }

    return set.size();
}

// 0
int packsack(vector<int> weight, vector<int> value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int>(BAG + 1, 0));
    int size = weight.size();
    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 1; i < size; i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[size - 1][BAG];
}

// TODO brute force - back tracking

// 13 分割等和子集
bool canPartition(const vector<int> nums) {
    int sum = 0;
    for(auto x : nums) {
        sum += x;
    }
    if(sum % 2) {
        return false;
    }
    int half = sum / 2;
    vector<int> dp[half + 1];

    for(int i = 0; i < nums.size(); i++) {
        for(int j = half; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return dp[half] == half ? true : false;
}

// 14 最后一块石头的重量II
int LastWeight(const vector<int> nums) {
    int sum = 0;
    for(auto x : nums) {
        sum += x;
    }
    int half = sum / 2;

    vector<int> dp[half + 1];

    for(int i = 0; i < nums.size(); i++) {
        for(int j = half; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return sum - dp[half] * 2;
}

// 19. 零钱兑换II
int change(vector<int> coins, int sum) {
    vector<int> dp(sum + 1, 0); // 组成sum有多少个方式

    dp[0] = 1;  // 注意，这里要设置为1, 否则计算出来的值全为0 ！！！！！！！！！！！！！！！！
    
    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= coins[i]; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    return dp[sum];
}

// 21. 组合总数IV
// dp[j] = dp[j] + dp[j - nums[i]]
// 先遍历物品，再遍历背包。是因为物品在外部循环，依次取nums[0, i)。所以nums0只能被先取，nums1只能被后取。
// 先遍历背包，再遍历物品。是因为物品在内部循环，物品0和物品1可以被反复循环取用。
int SumOfCombination(vector<int> nums, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;  // 凑成总数为0的组合，初始化为1
    for(int j = 0; j <= sum; j++) {
        for(int i = 0; i < nums.size(); i++) {
            if(j - nums[i] >= 0 && dp[j] < INT_MAX -dp[j - nums[i]]) {
                dp[j] += dp[j - nums[i]];
            }
        }
    }
    return dp[sum];
}

int main(void) {
    vector<int> nums{1, 2, 3, 3, 4, 5, 5, 6};
    cout << getLen4(nums) << endl;

    return 0;
}



// 1. 0-1 bagsack
// pick from items[0, i], put into BAG, what's the most value. cannot pick the same item
int DP_1(vector<int> weight, vector<int> value, int BAG) {
    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

// 2. complete pack
// pick from items[0, i], put into BAG, what's the most value. repeatly pick the same item is allowed.
int DP_2(vector<int> weight, vector<int> value, int BAG) {
    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = 0; j <= BAG; j++) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

// 3. combination

// there are different value coins, and amount
// how many ways to makeup the amount
// infinity amount of each coins
int DP_3(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, 0); // dp[j]: the ways to fill knapSack j
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++) {     // 1. loop starts from? from 0
        for(int j = 1; j <= amount; j++) {      // 2. loop starts from? from 1 or coins[i]
            // if(j < coins[i]) {               // 3. condition? if from 1, then if(j < coins[i]), so can be skipped
                // dp[j] = dp[j - 1];           // 4. what the solution under this condition? dp[j] = dp[j - 1]
            // } else {
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[amount];
}

// 4. permutation - 组合总数IV
// given an array of distinct integers nums and a target.
// return the number of possible combination that add up to target
int DP_4(vector<int> nums, int amount) {
    vector<int> dp(amount + 1, 0);
    // dp[i]: the permutation of choosen from nums[0, i]
    dp[0] = 1;
    for(int i = 0; i <= amount; i++) {
        for(int j = 0; j <= amount; j++) {
            if(i >= nums[j] && \
                dp[i] + dp[i - nums[j]] < INT_MAX) {    // 不作要求！但是此题目中提到了两个数相加可能超出计数范围的情况
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[amount];
}


// 5. least items to fill the knapsack
// different value of coins, and amount
// the minimal coins to makeup the amount
int DP_5(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            if(dp[j - coins[i]] != INT_MAX) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    if(dp[amount] == INT_MAX) {
        return -1;
    }
    return dp[amount];
}



// 5. least items to fill the knapsack
int coinsChange(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            if(coins[j - coins[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    return dp[amount];
}

int squareNumber(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    // dp[i]: 和为i的完全平方数的最少个数

    // dp[j] = min(dp[j], dp[j - nums[i]] + 1);
    for(int i = 1; i < n; i++) {
        for(int j = i; j * j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }
    return dp[n];
}

int rob_1(const vector<int> nums, int start, int end) {
    // if(nums.size() == 0) return 0;
    // if(nums.size() == 1) return nums[0];
    // if(nums.size() == 2) return max(nums[0], nums[1]);
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(dp[start], dp[start + 1]);

    for(int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[end];
}

int rob_2(const vector<int> nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    
    return max(rob_1(nums, 0, nums.size() - 2), rob_1(nums, 1, nums.size() - 1));
}

// stock
// buy and sell the stock, make the best benifit
int stock_1(vector<int> prices) {
    vector<vector<int>> dp(prices.size(), vector<int> (2, 0));
    // dp[i][0]: have stock
    // dp[i][1]: have NO stock
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);           // have stock.      [last day bought] vs [today bought]
        dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]); //have NO stock.    [last sold] vs [today sold]
    }

    return dp[prices.size() - 1][1];
}

int stock_1_greedy(vector<int> prices) {
    int low = 0;
    // int max = 0;
    int res = INT_MIN;

    for(int i = 0; i < prices.size(); i++) {
        low = prices[i] < low ? prices[i] : low;
        res = (prices[i] - low) > res ? (prices[i] - low) : res;
    }

    return res;
}

// stock 2: can trade multiple times. but must sell the stock before buy stock.
int stock_2(vector<int> prices) {
    vector<vector<int>> dp(prices.size(), vector<int> (2, 0));
    // dp[i][0]: have stock
    // dp[i][1]: have NO stock
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i] + dp[i - 1][1]);           // have stock.      [last day bought] vs [today bought]
        dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]); //have NO stock.    [last sold] vs [today sold]
    }

    return dp[prices.size() - 1][1];
}

// 41. longest incresing subsequence
// 本质上就是一个循环来遍历数据。分别计算出最长递增子序列的长度 - dp[i]。然后用res来获取各个dp[i]的最大值。
int lengthOfLIS(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    // vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    dp[0] = 1;  // dp[i]: nums[0, i]中，以nums[i]为结尾的最长递增子序列的长度
    int res = 0;

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[i - 1]) {
                dp[i] = max(dp[i], dp[j] + 1);  // 记录最长的dp[j] + 1
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

// 42. 
int lengthOfLCIS(vector<int> nums) {
    vector<int> dp(nums.size(), 1);
    int res = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}