
#include "test.hpp"


// 1
void delDup(vector<int>& nums) {
    // unordered_set<int> set;
    int size = nums.size();
    int pos = 1;

    for(int i = 1; i < size; i++) {
        int j;
        for(j = 0; j < i; j++) {
            if(nums[i] == nums[j]) {
                break;
            }
        }
        if(j == i) {
            nums[pos++] = nums[i];
        }
    }
    nums.resize(pos);
    
    for(auto it : nums) {
        cout << it << endl;
    }
}

void delDup(vector<int>& nums) {
    int size = nums.size();
    int pos = 0;
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] == nums[j]) {
                break;
            }
        }
        if(i == j) {
            nums[++pos] = nums[i];
        }
    }
    nums.resize(++pos);
}

void delAdjacentDup(vector<int>& nums) {
    int count = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            nums[count++] = nums[i];
            // count++;
        }
    }
    nums.resize(count);
    for(auto it : nums) {
        cout << it << endl;
    }
}

void delAdjacentDup(vector<int>& nums) {
    int count = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            nums[count++] = nums[i];
        }
    }
    nums.resize(count);
}

// 2
void delExtraSpaces(string& s) {
    int size = s.size();
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(s[i] != ' ') {
            if(j > 0) {
                s[j++] = ' ';
            }
        }
        while(i < size && s[i] != ' ') {
            s[j++] = s[i++];
        }
    }
    s.resize(j);
}

void delExtraSpaces(string& s) {
    int j = 0;
    int size = s.size();
    for(int i = 0; i < size(); i++) {
        if(s[i] != ' ') {
            if(j > 0) {
                s[j++] = ' ';
            }
        }
        while(i < size && s[i] != ' ') {
            s[j++] = s[i++];
        }
    }
    s.resize(j);
}

// 3
int longestUniqString(string s) {
    int hash[256];
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    int size = s.size();
    int pos = -1;
    int len = 0;
    int res = 0;
    int lhs = 0;
    int rhs = 0;

    for(int i = 0; i < size; i++) {
        pos = max(pos, hash[s[i]]);
        lhs = pos + 1;
        len = i - pos;
        rhs = i;
        if(len > res) {
            lhs = pos + 1;
            res = len;
            rhs = i;
        }
        hash[s[i]] = i;
    }

    cout << s.substr(lhs, rhs) << endl;
    
    return res;
}

int longestUniqString(string s) {
    int size = s.size();
    int hash[256];
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    int pos = -1;
    int len = 0;
    int res = 0;
    for(int i = 0; i < size; i++) {
        pos = max(pos, hash[s[i]]);
        len = pos - i;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}

// 4 - leetcode 209. 正整数数组中，sum >= k, 长度最小的子数组
int shortestArr(vector<int> nums, int k) {
    int lhs = 0;
    int size = nums.size();
    int sum = 0;
    int res = INT_MAX;

    for(int rhs = 0; rhs < size; rhs++) {
        sum += nums[rhs];
        while(lhs < size && sum >= k) {
            len = rhs - lhs + 1;
            res = max(res, len);
            sum -= nums[lhs++];
        }
    }
    return res == INT_MAX ? 0 : res;
}

it shortestArr(vector<int> nums, int k) {
    int lhs = 0, rhs = 0;
    int size = nums.size();
    int sum = 0, res = INT_MAX;
    for(int rhs = 0; rhs < size; rhs++) {
        sum += nums[rhs];
        while(sum >= k && lhs < size) {
            len = rhs - lhs + 1;
            res = max(res, len);
            sum -= nums[lhs++];
        }
    }
    return res == INT_MAX ? 0 : res;
}

// 5 - myStrtok
char* myStrtok(char* hay, const char needle) {
    static char* input = nullptr;
    if(hay != nullptr) {
        input = hay;
    }
    if(input == nullptr) {
        return nullptr;
    }

    char* res = (char*)malloc(sizeof(char) * 20);
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];
        } else {
            res[i] = '\0';
            input  = input + i + 1;
            return res;
        }
    }
    res[i] = '\0';
    input = nullptr;

    return res;
}

char* myStrtok(char* hay, const char needle) {
    char* input = hay;
    int i = 0;
    for( ; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = intput[i];
        } else {
            res[i] = '\0';
            return res;
        }
    }
    res[i] = '\0';
    return res;
}

// del duplicates for linkedlist
void delDupLL(pNode pHead) {
    pNode runner;
    pNode pPre;
    pNode pCur;
    pNode pNext;

    while(cur) {
        pRunner = pHead;
        while(pRunner != pCur) {
            if(pRunner->val == pCur->val) {
                pPre->next = pCur->next;
                pNode tmp = pCur;
                pCur = pCur->next;
                free(tmp);
                break;
            }
            pRunner = pRunner->next;
        }
        if(pRunner = pCur) {
            pPre = pCur;
            pCur = pCur->next;
        }
    }
}

// TODO using stack to delete adjacent duplicates
string recuDelAjacentDup(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(st.empty() || s[i] != st.top()) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }

    string res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int longestIncreasingSub(vector<int> nums) {
    int size = nums.size();
    int res = 0;
    vector<int> dp(size, 1);

    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }
    retrun res;
}

int longestIncreaseContinus(vector<int> nums) {
    int size = nums.size();
    int res = 0;

    vector<int> dp(size, 1);
    for(int i = 1; i < size; i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        res = max(res, dp[i]);
    }
    return res;
}

int dp_43(vector1, vector2) {
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    for(int i = 1; i <= size1; i++) {
        for(int j = 1; j <= size2; j++) {
            if(nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        res = max(res, dp[i][j]);
    }
    return res;
}

for(int i = 1; i < size; i++) {
    dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    res = max(res, dp[i]);
}
return res;

int dp_46() {
    for(int i = 1; i < size; i++) {
        dp[i] = max(dp[i], dp[i - 1] + nums[i]);
        res = max(res, dp[i]);
    }
    return re;
}

// max sum of subsequence
int dp_46_1(vector<int> nums) {
    
}

// nums1 - string     nums2 - substring
bool dp_47(vector<int> nums1, vector<int> nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));

    for(int i = 1; i < size1; i++) {
        for(int j = 1; j < size2; j++) {
            if(nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    dp[size1][size2]
}

int dp_32() {

}

int array_2(vector<int> nums, int target) {
    int size = nums.size();
    int lhs = 0;
    int rhs = size - 1;

    while(lhs <= rhs) {
        int mid = (lhs + rhs) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(target < nums[mid]) {
            lhs = mid + 1;
        } 
    }
}

int array_3() {
    int pos = 0;
    for(int i = 0; i < size; i++) {
        if(nums[i] != val) {
            nums[pos++] = nums[i];
        }
    }
    nums.resize(pos );
}

int array_4() {
    int lhs = 0;
    int rhs = size - 1;
    int pos = rhs;
    while(lhs < rhs) {
        if(pow(nums[lhs], 2) > pow(nums[rhs], 2)) {
            lhs++;
            numsNew[pos--] = pow(nums[lhs], 2);
        } else {

        }
        numsNew[pos] = max(pow(nums[lhs], 2), pow(nums[rhs], 2));
    }
}

int array_5() {
    int lhs = 0;
    int res = INT_MAX;
    int sum = 0;
    for(int rhs = 0; rhs < size; rhs++) {
        sum += nums[rhs];
        while(sum >= val && lhs < size) {
            len = rhs - lhs + 1;
            res = max(res, lhs);
            sum -= nums[lhs++];
        }
    }
    return res == INT_MAX ? 0 : res;
}

int array_6(int n) {
    int offset = 1;
    int N = n / 2;
    int startX = 0;
    int startY = 0;
    int offset = 1;
    while(N--) {
        int x = startX;
        int y = startY;
        for(; y < n - offset; y++) {
            mat[x][y] = cout++;
        }
        for(; x < n - offset; x++) {
            mat[x][y] = cout++;
        }
        for(; y > startY; y--) {
            mat[x][y] = cout++;
        }
        for(; x > startX; x--) {
            mat[x][y] = cout++;
        }
        startX++, startY++, offset++;
    }
    if()//odd
    ...
}

void rmLL(pNode* ppHead, int val){
    pNode* pp = ppHead;
    while((*pp)->val != val) {
        pp = &((*pp)->next);
    }
    if(*pp == nullptr) return;

    pNode tmp = *pp;
    *pp = (*pp)->next;
    free(tmp);
}

pPre = nullptr;
pCur = pHead;
pNext = nullptr;

while(pCur) {
    pNext = pCur->next;
    pCur->next = pPre;
    pPre = pCur;
    pCur = pNext;
}
return pPre;


pNode dummy;
dummy->next = pHead;

while(pCur && pCur->next) {
    pNode a = pCur->next;
    pNode b = pCur->next->next;
    pNode c = pCur->next->next->next;
    cur->next = b;
    c->next = a;
    a->next = b;
}

void* memAlign(size_t size, size_t alignment) {
    // 1. new len
    int offset = alignment - 1;
    int saveValSize = sizeof(size_t);
    int newSize = size + offset + saveValSize;

    // 2. malloc
    size_t* addr = (size_t*)malloc(newSize);

    // 3. the newAddr
    void* newAddr = (void*)((size_t)(addr + offset) & ~(offset));

    // 4. save the diff
    *(newAddr - 1) = newAddr - addr;

    return newAddr;
}

void align_free(void* alignedAddr) {
    void* addr = alignedAddr - *(alignAddr - 1);
    free(addr);
}

unordered_map<int, int> map;
for(i = 0; i < size; i++) {
    it = map.find(target - nums[i]);
    if(it != map.end()) {
        return {iter->second, i};
    }
    map.insert(pair<int, int>(nums[i], i));
}
return {};

void* memcpy(void* dst, const void* src, size_t size) {
    if(dst == nullptr || src == nullptr) return dst;

    if(src + size > dst) {
        
    }
}

int main(void) {
    string s = "abacadex";
    cout << longestUniqString(s) << endl;

    // string s = "   ab c  d   ";
    // delExtraSpaces(s);
    // cout << "pp" << s << "pp" << endl;

    // vector<int> nums{1, 1, 2, 2, 1, 3};
    // delDup(nums);

    // vector<int> nums{1, 1, 2, 2, 3, 3, 4};
    // delAdjacentDup(nums);

    return 0;
}