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

    // 倒三角形
    // 从最外层开始：[0, 0] -> [0, size - 1] 左闭，右开
    // [1, 1] -> [1, size - 2]
    // 直到中心点
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
// 扫描到cur就退出循环，
//      如果在到cur之前遇到一个节点的值与cur指向节点的值相同，
//          那么删除cur指向节点!!! 跳出循环（确保runner遍历过的范围无重复值），又开始从头一轮循环，
//      如果扫描到cur的时候才停止循环，说明前面没有重复的节点，
//          更新当前节点和它的前驱：pre = cur; cur = cur->next;

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
    pNode pHead = new node(3);  //or Node(3)
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
// TODO sort a stack in ascending order: 
// 思路：从s中弹出顶部元素到tmp，放到r中的适当位置。
// 通过与r中的顶部元素比较，如果比其小，就弹出r中的元素到s中。
// 直到找到比tmp大的元素。然后将tmp放到r中。如果比其大或者相等，就直接放入r中。如此循环到s为空
// 此刻，r是升序的栈
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

int main(void) {
    stack<int> s;
    s.push(10);
    s.push(12);
    s.push(8);
    
    stack<int> res = sort(s);
    while(!res.empty()) {
        cout << res.top() << endl;
        s.pop();
    }

    return 0;
}

// ===============================================================================================
// 5.1 将n的第i 到 j位，设置成m. 比如   1000,0000  的第1到3位，设置成101  ->    1000, 1010
int updateBits(int n, int m, int i, int j) {
    // 思路是将n的[j, i]清0， 然后与上m << i.  
    // 需要得到一个mask. 其[j, i]清0，其他位为全1
    
    int max = ~0; // FFFF,FFFF,FFFF,FFFF
    int left = max - ((1 << j) - 1);
    int right = ((1 << i) - 1);
    int mask = left | right;

    return (n & mask) | (m << i);
}

// ===============================================================================================
// 5.2
string intToBin(int num) {
    if(num == 0) return "0";

    string res;
    while(num > 0) {
        char mod = (num % 2) + '0';
        res = mod + res;
        num /= 2;
    }
    return res;
}

string decToBin(float num) {
    string res;
    
    while(num > 0) {
        if(res.size() > 32) {
            // return "ERROR";
            return res;
        }
        num *= 2;
        if(num >= 1) {
            res = res + "1";
            num -= 1.0;
        } else {
            res = res + "0";
        }
    }
    
    return res;
}

int main(void){
    float n = 8.14;
    string res_int = intToBin(n);

    float decimal = n - (int)n;
    string res_dec = decToBin(decimal);

    cout << res_int + "." + res_dec << endl;

    return 0;
}
// ===============================================================================================
// 5.4
// only one 1 in this binary numver
// ===============================================================================================
// 5.5 the number of bits required to convert integer A to integer B
int bitSwapRequired(int a, int b) {
    int c = a ^ b;
    int count = 0;
    // calculate the number of bits that are 1
    while(c > 0) {
        c = c & 1;
        c = c >> 1;
        count++;
    }
}
// ===============================================================================================
// 5.6 swap odd and even bits in an integer
int swapOddEvenBits(int num) {
    int res = (num & 0xaaaaaaaa) >> 1;
    res |= ((num & 0x55555555) << 1);

    return res;
}

// ===============================================================================================
// 8.1 fibo 
int fibo(int n) {
    // n = (n - 1) + (n - 2)
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibo_re(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;

    return fibo_re(n - 1) + fibo_re(n - 2);
}


// string 
int main() {
    // 1 1 2 3 5 8 13
    int res = fibo_re(6);
    cout << res << endl;

    return 0;
}
// ===============================================================================================
// 8.2 robot
int robot(const vector<vector<int>> mat) {
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));
    for(int i = 0; i < mat.size(); i++) {
        dp[i][0] = 1;
    }
    for(int j = 0; j < mat[0].size(); j++) {
        dp[0][j] = 1;
    }

    for(int i = 1; i < mat.size(); i++) {
        for(int j = 1; j < mat[0].size(); j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[mat.size() - 1][mat[0].size() - 1];
}

int robot_rec(int x, int y) {
    if(x == 0 || y == 0) {
        return 1;
    }
    return robot_rec(x - 1, y) + robot_rec(x, y - 1);;
}

// string 
int main() {
    int x = 3;
    int y = 3;
    int res = robot_rec(x - 1, y - 1);
    cout << res << endl;

    return 0;
}
// ===============================================================================================
// 8.3 return all subsets of a set

vector<vector<int>> dp;
vector<int> buf;
void printSubsets(const vector<int> nums, int k, int pos) {
    if(buf.size() == k) {
        dp.push_back(buf);
        return;
    }
    for(int i = pos; i < nums.size(); i++) {
        buf.push_back(i);
        printSubsets(nums, k, i + 1);
        buf.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    for(int i = 1; i <= nums.size(); i++) {
        printSubsets(nums, i, 0);
    }

    for(auto x : dp) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
// ===============================================================================================
// 8.4 permutation - string is the same

vector<vector<int>> dp;
vector<int> buf;
void permutation(vector<int> nums, int k, int pos) {
    if(pos >= k) {
        dp.push_back(nums);
        return;
    }
    for(int i = pos; i < nums.size(); i++) {
        if(i != pos && nums[i] == nums[pos]) {
            continue;       // 去重，比如nums中有相同的元素
        }
        std::swap(nums[i], nums[pos]);
        permutation(nums, k, pos + 1);
        std::swap(nums[i], nums[pos]);
    }
}

int main(void) {
    vector<int> nums = {1, 3, 3, 4};

    permutation(nums, 4, 0);

    for(auto x : dp) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
// ===============================================================================================
// TODO 8.5
// ===============================================================================================
// TODO 8.6
// ===============================================================================================
// 8.7 填满背包的方式
int fillBag(vector<int> nums, int BAG) {
    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < nums.size(); i++) {
        for(int j = nums[i]; j <= BAG; j++) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[BAG];
}
//TODO 给出的递归方法
// ===============================================================================================
// TODO 8.8 八皇后
// ===============================================================================================
// 9.1
void merge_2(vector<int> a, vector<int> b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int k = a.size() + b.size() - 1;

    while(i >= 0 && j >= 0) {
        if(a[i] > b[j]) {
            a[k] = a[i];
            i--;
        } else {
            a[k] = b[j];
            j--;
        }
        k--;
    }
    
    while(j >= 0) {
        a[k] = b[j];
        k--, j--;
    }
}
// ===============================================================================================
// 对string进行排序，作为index，然后用map将其与原始数据关联。map本身会排序。
// 所以，接下来只需要将map读出，然后放在arr中。
namespace chapter_9 {
    void anagramSort(vector<string>& array) {
        map<string, vector<string>> strMap;

        for(const string& str : array) {
            string sortedStr = str;
            sort(sortedStr.begrin(), sortedStr.end()); // 对array的每个string分别排序

            if(strMap.find(sortedStr) != strMap.end()) { // 如果找到了
                strMap[sortedStr].push_back(str);
            } else {                                    // 如果没找到，就会返回map::end;
                vector<string> anagramVector = {str};
                strMap[sortedStr] = anagramVector;
            }
        }

        int index = 0;
        for(const std::pair<str, vector<string>> pair : strMap) {
            for(const string& anagramStr : pair.second) {
                array[index] = anagramStr;
                index++;
            }
        }
    }
}

// ===============================================================================================
// 9.5 find the location of a given string

int search_(const vector<string> strings, int left, int right, string target) {
    while(left <= right) {
        while(left <= right && (strings[right] == "")) {
            right--;
        }

        if(left > right) {
            return -1;
        }

        int mid = (left + right) / 2;
        while(strings[mid] == "") {
            mid++;
        }
        int res = target.compare(strings[mid]);
        if(res == 0) {
            return mid;
        } else if(res < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int search(const vector<string> strings, string str) {
    if(strings.empty() == 1 || str.empty() == 1) {
        return -1;
    }
    if(str == "") {
        for(int i = 0; i < strings.size(); i++) {
            if(strings[i].compare(str) == 0) {
                return i;
            }
        }
    }
    return search_(strings, 0, strings.size() - 1, str);
}

int main(void) {
    vector<string> s = {"abc", "", "xy", "", "", "kgb"};
    string q = "kgb";
    cout << search(s, q) << endl;

    return 0;
}
// ===============================================================================================
// 9.6 row and column sorted, find the an element in it
bool findElem(vector<vector<int>> mat, int target) {
    int row = 0;
    int col = nums[0].size() - 1;

    while(row < nums.size() && col >= 0) {
        if(mat[row][col] == target) {
            return true;
        } else if(target < mat[row][col]) {
            col--;
        } else {
            row++;
        }
    }
    return false;
}
// ===============================================================================================
// 9.7
int cmp(const void *x, const void *y) {
    int *a = (int *)x;
    int *b = (int *)y;

    if(*a != *b) {
        return *a - *b;
    }
    return *(a + 1) - *(b + 1);
}

void rmEle(void *p, int row, int col) {
    int (*mat)[col] = p;
    for(int i = 0; i < row - 1; i++) {
        if(mat[i + 1][1] < mat[i][1]) {
            // TODO 删除mat[i][0] and mat[i][1]; 或者新的数组中不取这两个数
        }
    }
}

int main(void) {
    int mat[][2] = {{1, 5}, {3, 8}, {3, 0}};
    qsort(mat, 3, sizeof(mat[0]), cmp);
    for(int i = 0; i < 3; i++) {
        cout << mat[i][0] << " " << mat[i][1] << endl;
    }
    cout << sizeof(mat) / sizeof(mat[0]) << endl;
    int row = sizeof(mat) / sizeof(mat[0]);
    int col = sizeof(mat[0]);
    for(int i = 0; i < row - 1; i++) {
        if(mat[i + 1][1] < mat[i][i]) {
            rmEle(mat, i + 1, col);
        }
    }

    return 0;
}
// ===============================================================================================
// ===============================================================================================
// ===============================================================================================