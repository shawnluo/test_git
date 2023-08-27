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
    for(int i = start, j = end; i < j; i++, j--) {
        std::swap(s[i], s[j]);
    }
}

string reverseStr2(string s, int k) {
    int size = s.size();
    int index = 0;
    while(index < size) {
        if((size - index) < k) {
            reverse(s, index, size - 1);
            break;
        } else if((size - index) < 2 * k) {
            reverse(s, index, index + k - 1);
            break;
        } else {
            reverse(s, index, index + k - 1);
            index += 2 * k;
        }
    }
    return s;
}

int main(void) {
    char s[] = "abcdefghikl";
    reverseStr2(s, 3);
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

// ----------------------- 字符串 04-07
// LeetCode：459.重复的子字符串
bool isRepeat(string s, string sub) {
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