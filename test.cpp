


#include "test.hpp"
#include <thread>

using namespace std;


int myRead(char* buf, int n) {
    int readChar = 4;
    int copiedChar = 0;
    char buf4[4] = {0};

    for(; readChar == 4 && copiedChar < n; ) {
        readChar = read4(buf4);

        for(int i = 0; i < readChar; i++) {
            if(copiedChar == n) return copiedChar;

            buf[copiedChar++] = buf4[i];
        }
    }
    return copiedChar;
}

int partition(int* nums, int lhs, int rhs) {
    int j = -1;
    int pivot = nums[rhs];
    for(int i = lhs; i < rhs; i++) {
        if(nums[i] < pivot) {
            swap(nums[++j], nums[i]);
        }
    }
    swap(nums[++j], nums[rhs]);
    return j;
}

void quickSort(int* nums, int start, int end) {
    if(start < end) {
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

bool isLittleEnd() {
    int x = 1;
    char* p = (char*)&x;

    return *p == 1 ? true : false;
}


int count = 1;
for(int i = 1; i < n; i++) {
    if(s[i] != s[i - 1]) {
        s[count++] = s[i];
    }
}
s.resize(count);


int pos = 1;
for(int i = 1; i < n; i++) {
    for(int j = 0; j < pos; j++) {

    }
}

void delDupLL() {
    pNode pPre = pHead;
    pNode pCur = pHead->next;
    pNode pNex;

    while(pCur) {
        pNode pRunner = pHead;

        while(pRunner != pCur) {
            if(pRunner->val == pCur->val) {
                pNode tmp = pCur;
                pPre->next = pCur->next;
                pCur = pCur->Next;
                delete tmp;
            }
            pRunner = pRunner->next;
        }
        if(pRunner == pCur) {
            pPre = pCur;
            pCur= pCur->next;
        }
    }
}

int delExtraSpace(string& s) {
    int n = s.size();
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != ' ') {
            if(j > 0) {
                s[j++] = ' ';
            }
            while(i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }
    }
    s.resize(j);
}

void spiralMat() {
    while(N--) {
        int x = startX;
        for(; y < n - offset - 1; y++) {
            mat[x][y] = count++;
        }
    }
}

pNode reverseLL() {
    pNode pPre = nullptr;
    pNode pCur = pHead;
    pNode pNex = nullptr;

    for(; pCur; ) {
        pNode tmp = pCur;
        pCur->next = pHead;
        pPre = pCur;
        pCur = pNex;
    }
    return pPre;
}

int meetingRoom(vector<vector<int>>& room) {
    int count = 0;
    int n = room.size();
    vector<int> start;
    vector<int> end;

    for(auto x : room) {
        start.push_back(x[0]);
        end.push_back(x[1]);
    }
    
    int pEnd = 0;
    for(int pStart = 0; pStart < n; pStart++) {
        if(pStart == 0 || start[pStart] < end[pEnd]) {
            count++;
        } else {
            pEnd++;
        }
    }
    return count;
}

void* alignedMalloc(size_t align, size_t size) {
    size_t offset = align - 1;
    size_t newSize = size + offset + sizeof(size_t);
    size_t* addr = (size_t*)malloc(newSize);
    void* newAddr = (void*)((size_t)(addr + offset) & ~(offset));
    *(newAddr - 1) = newAddr - addr;

    return newAddr;
}

void alignFree(void* alignedAddr) {
    void* addr = (size_t*)alignedAddr - *(alignedAddr - 1);
    free(addr);
}

void getNext(int* next, string& s) {
    next[0] = 0;
    int j = 0;

    for(int i = 1; i < size; i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[j] == s[i]) {
            j++;
        }
        next[i] = j;
    }
}

int isSub() {
    getNext();
    int j = 0
    for()
}

int rob() {
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
}

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

return dp[n - 1][BAG];

for(int i = 0; i < weight.size(); i++) {
    for(int j = BAG; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
return dp[BAG];

for(int i = 1; i < size; i++) {
    for(int j = 0; j < i; j++) {
        if(nums[i] > nums[j]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
}

for() {
    if(nums[i] > nums[i - 1]) {
        dp[i] = dp[i - 1] + 1;
    }
    res = max(res, dp[i]);
}

/*
// TODO 
ok - meeting room
# - aligned memory
- bitwise
ok - blur
- dp --------

ok - delete adjacent dup
ok - remove dup for array

ok - remove dup for linkdelist
ok - remove additional spaces

- sink island
ok - spiral mat
ok - reverse ll
- kmp
*/

void* memAlign(size_t size, size_t alignment) {
    1. addr = malloc(newSize)
    2. get the newAddress
    3. save the addr for free()
    4. return newAddress 
}

void* memcpyAlign(size_t alignment, void* dst, void* src, size_t dstLen, size_t srcLen) {
    1. get the newAddress
        1. offset = alignment - 1
        2. newAddr = dst + offset & ~(offset)
    2. memcpy
    4. return newAddr

    size_t offset = alignment - 1;
    // size_t newLen = srcLen + offset;
    // size_t* addr = (size_t)malloc(newLen);
    // if(!addr) return nullptr;

    size_t* newAddr = ((size_t*)dst + offset) & ~(offset);
    size_t cpuSize = sizeof(size_t);
    size_t t1 = srcLen / cpuSize;   // cpu size count
    size_t t2 = srcLen % cpuSize;   // remain byte count
    
    size_t* d = (size_t*)dst;
    size_t* s = (size_t*)src;

    for(int i = 0; i < t1; i++) {
        *d++ = *s++;
    }

    d = (size_t*)((size_t)dst + t1 - cpuSize);
    s = (size_t*)((size_t)src + t1 - cpuSize);
    char* d1 = (char*)d;
    char* s1 = (char*)s;
    for(int i = 0; i < t2; i++) {
        *d1++ = *s1++;
    }

}

int main(void) {
    string s = "aabcdebbce";
    removeDup(s);
    cout << s << endl;

    return 0;
}