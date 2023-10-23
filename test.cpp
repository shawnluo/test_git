#include "test.hpp"


// TODO
// int dp_24(int n) {
//     for(int i = 0; i <= n; i++) {
//         for(int j = 1; j * j <= i; j++) {
//             dp[i] = min(dp[i], dp[i - j * j] + 1);
//         }
//     }
//     return dp[n];
// }

// TODO
// int dp_48() {

// }

// TODO
// 给定一个字符串，计算这个字符串中有多少个回文子串
// int dp_52() {
//     int res = 0;
//     for(int i = s.size() - 1; i >= 0; i--) {
//         for(int j = i + 1; j < s.size(); j++) {
//             if(s[i] == s[j]) {
//                 if(j - 1 <= 1) {
//                     res++;
//                     dp[i][j] = true;
//                 } else if(dp[i + 1][j - 1] == true) {
//                     res++;
//                     dp[i][j] = true;
//                 }
//             }
//         }
//     }
//     return res;
// }

// TODO
// 最长回文子序列: "bbbab" -> "bbbb"  4
// int dp_53() {
//     for(int i = 0; i < s.size(); i++) dp[i][i] = 1;

//     for(int i = s.size() - 1; i >= 0; i--) {
//         for(int j = i + 1; j < s.size(); j++) {
//             if(s[i] == s[j]) {
//                 dp[i][j] = dp[i + 1][j - 1] + 2;
//             } else {
//                 dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     return dp[0][s.size() - 1];
// }

void cc_1_7(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> shadow(row, vector<int>(col, 0));

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(mat[i][j] == 0) {
                for(int m = 0; m < row; m++) shadow[m][j] = 1;
                for(int n = 0; n < col; n++) shadow[i][n] = 1;
            }
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(shadow[i][j] == 1) {
                mat[i][j] = 0;
            }
        }
    }
}

void cc_1_8(string s1, string s2) {
    // isSubstring(s, sub)

    s1 = s1 + s1;

    return isSubstring(s1, s2);
}

void cc_2_1(pNode pHead) {
    pNode pCur = pHead->next;
    pNode pPre = pHead;

    while(pCur) {
        pNode pRunner = pHead;
        while(pRunner != pCur) {
            if(pRunner->val == pCur->val) {
                pPre->next = pCur->next;
                pCur = pCur->next;
                break;
            }
        }
        if(pRunner == pCur) {
            pPre = pCur;
            pCur = pCur->next;
        }
    }
}

void cc_2_2(pNode pHead, int n) {
    pNode p = pHead;

    for(int i = 0; i <= n; i++) {
        p = p->next;
    }

    pNode pCur = pHead;
    while(p) {
        pCur = pCur->next;
        p = p->next;
    }

    return pCur;
}

void cc_2_3() {
    tmp = p->next;
    p->val = p->next->val;
    p->next = p->next->next;
    free(tmp);
    // delete tmp;
}

pNode cc_2_4(pNode p1, pNode p2) {
    // if()
    int carry = 0;
    while(p1 || p2) {
        int val = carry;
        if(p1) {
            val += p1->val;
            p1 = p1->next;
        }
        if(p2) {
            val += p2->val;
            p2 = p2->next;
        }
        val += carry;
        carry = val % 10;
        val = abs(val - 10);

        addLL(p, val);
    }
    if(carry) addLL(p, carry);

    return p;
}

pNode cc_2_5(pNode p) {
    pNode pFast = p;
    pNode pSlow = p;

    while(pFast && pFast != pSlow) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }

    pFast = pHead;
    while(pFast != pSlow) {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    return pFast;
}

int array[300] = {0};
int pointer[3] = {0};
void push(int st, int val) {
    int offset = 100 * st + pointer[st];
    if(st == 0) {
        arr[++offset] = val;
    }
}

int pop(int st) {
    int offset = 100 * st + pointer[st];
    int res = arr[offset--];
    return res;
}

int peek() {

}

int isFull() {

}

// cc_3_2
int min_peek() {
    if(s2.isEmpty()) {
        return INT_MAX;
    } else {
        return s2.peek();
    }
}

void push(int val) {
    if(val <= min_peek()) {
        s2.push(value);
    }

    st.push(val);
}

int pop() {
    int val = st.pop();
    if(val == min_peek()) {
        s2.pop();
    }
    return val;
}

// cc_3_4
void move(char x, char y) {
    cout << 'x' << " -> " << 'y' << endl;
}

void hanoi(int n, char a, char b, char c) {
    if(n == 1) {
        move(a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    move(a, c);
    hanoi(n - 1, b a, c);
}

// cc_3_5
int pop(int val) {
    while(!stIn.empty()) {
        stOut.push(stIn.top);
        stIn.pop();
    }
    int res = stOut.top();
    stOut.pop();

    return res;
}

void push(int val) {
    stIn.push(val);
}

// cc_3_6
// push(int val)
// pop()
// peek()
// isEmpty()

void sortSt(vector<int>& nums) {
    st.push(nums[0]);
    for(int i = 1; i < nums.size(); i++) {
        while(!st.isEmpty() && nums[i] > st.peek()) {
            bak.push(st.top());
            st.pop();
        }
        st.push(nums[i])
        while(!bak.isEmpty()) {
            st.push(bak.top());
            bak.pop();
        }
    }
    int i = 0;
    while(!st.isEmpty()) {
        nums[i++] = st.top();
        st.pop();
    }
}

// cc_5_1
int left = (1 << j) - 1;
int right = (1 << i) - 1;
int AllOne = left - right;  // all 1 between left and right
int AllZero = ~AllOne;
N &= AllZero;
M <= i;
N |= M;

// cc_5_2
string int_str = "";
while(intPart > 0) {
    int r = intPart % 2;
    intPart >>= 1;
    int_string += r;
}

// cc_5_5
int bitConvert(int a, int b) {
    int x = a ^ b;
    int res = 0;
    while(x) {
        x &= (x - 1);
        res++;
    }
    return res;
}

// cc_5_6
int cc_5_6(int n) {
    return ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
}

int cc_8_1(int n) {
    if(n <= 1) return n;
    return cc_8_1(n - 1) + cc_8_1(n - 2);
}

int cc_8_2(vector<vector<int>> mat, int x, int y) {
    if(x == 0) return 1;
    if(y == 0) return 1;

    if(x > 0 && x < mat.size() && y > 0 && y < mat[0].size())
        return cc_8_2(mat, x - 1, y) + cc_8_2(mat, x, y - 1);
}

int cc_8_2_2(vector<vector<int>> mat) {
    vector<vector<int>> dp(mat.size(), vector<int> (mat[0].size(), 0));
    int m = mat.size();
    int n = mat[0].size();
    for(int i = 0; i < m; i++) dp[i][0] = 1;
    for(int j = 0; i < n; j++) dp[0][j] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[m - 1][n - 1];
}

// cc_8_3
vector<vector<int>> getSet(vector<int> nums, int pos) {

}

// cc_8_4
void permu(string s, int pos) {
    if(pos == s.size()) {
        cout << s << endl;
    }
    for(int i = pos; i < s.size(); i++) {
        swap(s[i], s[pos]);
        permu(s, i + 1);
        swap(s[i], s[pos]);
    }
}

int cc_8_7(vector<int> nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j <= target; j++) {
            if(j >= nums[i]) {
                dp[j] += dp[j - nums[i]];
            }
        }
    }
    return dp[target];
}

void cc_9_1(vector<int>& a, vector<int> b) {
    int size1 = a.size();
    int size2 = b.size();
    int size = size1 + size2;

    a.resize(size);
    size1--;
    size2--;
    size--;

    while(size >= 0) {
        if(a[size1] > b[size2]) {
            a[size--] = a[size1--];
        } else {
            a[size--] = b[size2--];
        }
    }
}

int search() {
    while(left <= right) {
        while(left <= right && string[right] == "") {
            right--;
        }
        if(left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        while(string[mid] == "") {
            mid++;
        }
        int res = target.compare(strings[mid]);
        if(res == 0) return mid;
        else if(res < 0) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int row = 0;
int col = size - 1;

while(row < M && col >= 0) {
    if(target < nums[row][col]) col--;
    else if(target > nums[row][col]) row++;
    else return nums[row][col];
}