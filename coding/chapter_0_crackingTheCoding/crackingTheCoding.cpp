#include "test.hpp"


// 1.1
bool isUniq(const string s) {
    vector<int> hash(256, 0);

    for(int i = 0; i < s.size(); i++) {
        if(hash[s[i]]++) {
            return false;
        }
    }
    return true;
}

int main(void) {
    string s = "abcbd";
    cout << isUniq(s) << endl;

    return 0;
}

// ===============================================================================================
// 1.2 reverse a C-style String
void reverse(string& s) {
    int len = s.size();
    if(len == 0) {
        return;
    }

    char *left = s;
    char *right = s + len - 1;

    while(left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
    }
}

// using string, and using str.c_str() to convert string to char *
void reverseString(const std::string& str) {
    char* reversedStr = new char[str.length() + 1];
    const char* originalStr = str.c_str();
    
    int j = str.length() - 1;
    for (int i = 0; i < str.length(); i++) {
        reversedStr[i] = originalStr[j];
        j--;
    }
    reversedStr[str.length()] = '\0';
    
    std::cout << "Reversed string: " << reversedStr << std::endl;
    
    delete[] reversedStr;
}

int main(void) {
    // string s = "abcd";
    char s[] = "abcd";
    reverse(s);
    cout << s << endl;

    return 0;
}

// ===============================================================================================
// 1.3
// abcdab -> abcd
static void removeDuplicateStr(char* s) {
    if (s == nullptr) {
        return;
    }
    int len = strlen(s);
    if(len < 2) {
        return;
    }

    int left = 0;
    int right = 0;
    int tail = 1;
    for (int i = 1; i < len; i++) {
        int j;
        for(j = 0; j < tail; j++) {
            if(s[i] == s[j]) {
                break;
            }
        }
        if(j == tail) {
            s[tail++] = s[i];
        }
    }
    s[tail] = 0;
}

// using buffer
static void removeDuplicateStr_2(char* s) {
    if(s == nullptr) {
        return;
    }
    int len = strlen(s);
    bool hit[256] = {0};
    int tail = 1;
    hit[s[0]] = true;
    
    for(int i = 1; i < len; i++) {
        if(hit[s[i]] == 0) {
            s[tail] = s[i];
            tail++;
            hit[s[i]] = true;
        }
    }
    s[tail] = 0;
}

int main(void) {
    // string s = "abcd";
    char s[] = "abcdacx";
    removeDuplicateStr(s);
    cout << s << endl;

    return 0;
}

// ===============================================================================================
//1.4 isAnagram
bool isAnagram(string s, string t) {
    vector<int> hash(256, 0);
    for(int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }

    for(int i = 0; i < t.size(); i--) {
        hash[t[i]]--;
    }
    
    for(int i = 0; i < 256; i++) {
        if(hash[i] != 0) {
            return false;
        }
    }
    return true;
}

// ===============================================================================================
//1.5 replace all spaces with a string with "%20"
void replaceStr(string s) {
    int len = s.size();
    int len_new;
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] == ' ') {
            count++;
        }
    }

    len_new = len + coun * 2;
    s[len_new] = '\0';

    len -= 1;
    len_new -= 1;
    while(len >= 0) {
        if(s[len] == ' ') {
            s[len_new--] = '0';
            s[len_new--] = '2';
            s[len_new--] = '%';
            len--;
        } else {
            s[len_new--] = s[len--];
        }
    }
}

// ===============================================================================================
// 1.6 rotate N * N mat
void showMe(const vector<vector<int>> mat) {
    for (auto x : mat) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int>>& mat) {
    int len = mat.size();

    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
            int save                      = mat[i][j];
            mat[i][j]                     = mat[j][len - 1 - i];
            mat[j][len - 1 - i]           = mat[len - 1 - i][len - 1 - j];
            mat[len - 1 - i][len - 1 - j] = mat[len - 1 - j][i];
            mat[len - 1 - j][i]           = save;

            // mat[i][j] = mat[len - 1 - j][i];
        }
    }
}
int main(void) {
    // string s = "abcd";
    vector<vector<int>> mat = { { 1, 2, 3 }, { 8, 9, 4 }, { 7, 6, 5 } };

    showMe(mat);
    rotate(mat);
    cout << endl;
    showMe(mat);

    return 0;
}
// ===============================================================================================
// 1.7 mat[][] if an element in an MxN matrix is 0, then clear row and col
void setZeros(vector<vector<int>>& mat) {
    if(mat == 0) return;

    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> _mat(row, vector<int> (col, 0));

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(mat[i][j] == 0) {
                for(int x = 0; x < row; x++)
                    _mat[x][j] = 1;
                for(int y = 0; y < col; y++)
                    _mat[i][y] = 1;
            }
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(_mat[i][j] == 1) {
                mat[i][j] = 0;
            }
        }
    }
}

// ===============================================================================================
// 1.8 check if s2 is a rotation of s1
bool isRotation(string s1, string s2) {
    if(s1 == 0 || s2 == 0 || s1.size() != s2.size()) return false;

    string s = s1 + s2;
    return isSubstring(s, s2);
}

// ===============================================================================================
// 2.1 remove duplicates form an unsorted linked list
typedef struct Node {
    int data;
    struct Node* next;

    Node(int val) : data(val), next(nullptr) {}
} node, *pNode;

void showMe(pNode pHead) {
    if(!pHead) return;

    while(pHead) {
        cout << pHead->data << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

// 算法思想：
// 定义一个指针cur，指向当前没有重复元素的那部分的下一个元素，pre指向cur的前驱，
// 比如2→3→2→5→4→3→7→6→7为当前链表的形状，刚开始cur指向3，pre指向2，定义一个工作指针runner，每次从head开始向后扫描，
// 扫描到cur就退出循环，如果在到cur之前遇到一个节点的值与cur指向节点的值相同，
// 那么删除cur指向节点，跳出循环（确保runner遍历过的范围无重复值），又开始新一轮循环，
// 如果扫描到cur的时候才停止循环，说明前面没有重复的节点，更新当前节点和它的前驱：pre = cur; cur = cur->next;

void delD(pNode pHead) {
    if(pHead == nullptr) return;

    pNode pre = pHead;
    pNode cur = pre->next;
    while(cur != nullptr) {
        pNode runner = pHead;
        while(runner != cur) {
            if(runner->data == cur->data) {
                pre->next = cur->next;
                cur = cur->next;
                break;
            }
            runner = runner->next;
        }
        if(runner == cur) {
            pre = cur;
            cur = cur->next;
        }
    }
}

// 使用set和set中的count函数
void deleteDups2(pNode pHead) {
    set<int> s;
    pNode cur = pHead;
    while (cur & cur->next) {
        s.insert(cur->data);           // 将当前的节点数据放入set中
        if (s.count(cur->next->val)) { // 如果发现下一个节点重复，就将下一个指针指向下下个节点 - 不移动当前指针！
            cur->next = cur->next->next;
        } else {
            cur = cur->next;            // 指针指向下一个节点
        }
    }
}

int main(void) {
    pNode pHead = new node(3);
    pNode p1 = new node(3);
    pNode p2 = new node(3);
    pNode p3 = new node(4);
    pNode p4 = new node(5);

    pHead->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    delD(pHead);
    showMe(pHead);

    return 0;
}

// ===============================================================================================
// 2.2 nth to the last
pNode nthToLast(pNode pHead, int n) {
    pNode left = pHead;
    pNode right = pHead;
    for(int i = 0; i < n; i++) {
        right = right->next;
    }
    while(right) {
        left = left->next;
        right = right->next;
    }
    return left;
}

// ===============================================================================================
// 2.3
void deleteNode(pNode pHead, pNode n) {
    if(n == nullptr) return;

    pNode tmp = n->next;
    n->data = n->next->data;
    n->next = n->next->next;
    delete tmp;
}

// ===============================================================================================
// 2.4
void appendLL(pNode& pHead, int value) {
    if(pHead == nullptr) {
        pHead = new node(value);
        return;
    }
    pNode p = pHead;
    while(p->next) {
        p = p->next;
    }
    pNode pNew = new node(value);
    p->next = pNew;
}

pNode addLists(pNode L1, pNode L2) {
    if(L1 == nullptr || L2 == nullptr) return nullptr;

    pNode result;
    int data = 0;
    int carry = 0;
    while(L1 || L2) {
        if(L1) {
            data += L1->data;
            L1 = L1->next;
        }
        if(L2) {
            data += L2->data;
            L2 = L2->next;
        }
        data += carry;
        if(data >= 10) {
            carry = 1;
            data -= 10;
        } else {
            carry = 0;
        }
        appendLL(result, data);
    }
    if(carry != 0) {
        appendLL(result, carry);
    }

    return result;
}
// ===============================================================================================
// 2.5 find the entry of circle
pNode findBeginning(pNode pHead) {
    if(pHead == nullptr) return nullptr;
    if(pHead->next == pHead) return pHead;

    pNode pSlow = pHead->next;
    pNode pFast = pHead->next->next;
    while(pSlow != pFast) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }
    
    pFast = pHead;
    while(pSlow != pFast) {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }

    return pFast;
}
// ===============================================================================================
// 3.1
// use a single array to implement three stacks
// [0, 99]
// [100, 199]
// [200, 299]
int stackSize = 100;
int buffer[3 * stackSize] = {0};
int stackPointer[3] = {0, 0, 0}; // 分别指向三个栈的栈顶
void push(int stackNum, int value) {
    int index = stackNum * stackSize + stackPointer[stackNum] + 1;
    stackPointer[stackNum]++;
    buffer[index] = value;
}
int pop(int stackNum) {
    if(isEmpty == false) {
        int index = stackNum * stackSize + stackPointer[stackNum];
        return buffer[index--];
    }
}
int peek(int stackNum) {
    int index = stackNum * stackSize + stackPointer[stackNum];
    return buffer[index];
}
bool isFull(int stackNum) {
    return stackPointer[stackNum] == (stackNum + 1) * stackSize -1;
}
boot isEmpty(int stackNum) {
    return stackPointer[stackNum] == stackNum * stackSize;
}

// ===============================================================================================
// 3.2 新建一个stackMIN. 
    // 1. 当push的元素小于或等于该栈顶的元素，则push入该栈.
    // 2. 当pop的元素等于其栈顶的元素，则pop出该栈
void push(int value) {
    if(value <= stackMIN_peek()) {
        stackMIN_push(value); // stackMIN入栈
    }
    stack[++p] = value;
}

int pop() {
    if(stack[p] == stackMIN_peek()) {
        stackMIN_pop(); // stackMIN出栈
    }
    return stack[p--];
}
// ===============================================================================================
// 3.4
void move(char x, char y) {
    cout << x << " -> " << y << endl;
}

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        move(a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    move(a, c);
    hanoi(n - 1, b, a, c);
}

int main(void) {
    hanoi(4, 'a', 'b', 'c');
    return 0;
}
// ===============================================================================================
// 3.5 implement a queue by using 2 stacks
    // 1. using stack_2 to push data
    // 2. pop date from stack_1
void quePush(int value) {
    if(ifFull(stack_2) != true)
        push(stack_2, value);
}

int quePop() {
    if(isEmpty(stack_1)) {
        push(stack_1, pop(stack_2));
    }
    return pop(stack_1);
}
// ===============================================================================================
// 3.6
// TODO sort a stack in ascending order
stack<int> sort(stack<int>& s) {
    stack<int> r;
    while(!s.empty()) {
        int tmp = s.top();
        s.pop();
        while(!r.empty() && r.top() > tmp) {
            s.push(r.top());
            r.pop();
        }
        r.push(tmp);
    }
    return r;
}
// ===============================================================================================
// ===============================================================================================
// ===============================================================================================
// ===============================================================================================
// ===============================================================================================
// ===============================================================================================