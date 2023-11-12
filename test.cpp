
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
        for(int j = 0; j < i; j++) {
            if(i - nums[i] != INT_MIN)
            dp[i] = max(dp[i], dp[i - nums[j] + nums[j]]);
        }
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