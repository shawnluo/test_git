
#include "test.hpp"

int leastInterval(vector<char>& tasks, int n) {
    int freq[26] = {0};
    for(char ch : tasks) {
        freq[ch - 'a']++;
        // cout << freq[ch - 'a'] << endl;
    }

    priority_queue<int> pq;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            pq.push(freq[i]);
        }
    }

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    // int time = 0;
    // while(!pq.empty()) {
    //     int cycle = n + 1;
    //     while(cycle-- && !pq.empty()) {
    //         if(pq.top() > 1) {
    //             store.push_back(pq.top() - 1);
    //         }
    //     }
    // }

    return 0;
}

vector<int> topKFreq(vector<char>& v, int k) {
    // unordered_map<int, int> umap = {
    //     {5, 50},
    //     {2, 20},
    //     {9, 90},
    //     {1, 10},
    //     {3, 30}
    // };

    unordered_map<char, int> umap;
    for(auto i = 0; i < v.size(); i++) {
        umap[v[i]]++;
    }

    // for(auto it : umap) {
        // cout << it.first << " " << it.second << endl;
    // }

    // vector<pair<int, int>> vec(umap.begin(), umap.end());
    // sort(vec.begin(), vec.end());
    // sort(vec.end(), vec.begin(), [](const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.second < b.second; // sort by the second element of the pair
    // });

    // for(const auto& it : vec) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // sort(umap.begin(), umap.end());

    // vector<pair<char, int>> mapV(umap.begin(), umap.end());
    // sort(mapV.begin(), mapV.end());

    // for(auto it : mapV) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // priority_queue<pair<char, int>> pq;
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    for(auto it : umap) {
        pq.push(it);
    }

    while(!pq.empty()) {
        // auto topPair = pq.top();
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return {};
}

void test() {
    vector<char> v = {'a', 'b', 'c', 'a', 'b', 'a'};
    // for(auto it : v) {
    for_each(v.begin(), v.end(), [](char num) {
        cout << num << endl;
    });

    unordered_map<char, int> umap;
    for(auto it : v) {
        umap[it]++;
    }

    // priority_queue<pair<char, int>> pq;
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

    for(auto it : umap) {
        pq.push(it);
    }

    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}

void test1() {
    // conti shangsheng chuan changdu
    vector<int> v{1, 2, 3, 1, 8};
    int ret = 1;
    auto n = v.size();
    // vector<int> dp();

    for(int i = 1; i < v.size(); i++) {
        if(v[i] < v[i - 1]) {
            break;
        }
        ret++;
    }
    cout << ret << endl;
}

void test2() {
    vector<int> v{1, 2, 3, 1, 6, 8, 5};
    int res = 1;
    // int max = 1;
    int n = v.size();
    // cout << n << endl;
    vector<int> dp(n, 1);
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }
    cout << dp[n - 1] << " " << res << endl;
}

/* vector<vector<int>> matrix(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> res;
    int na = a.size();
    int nb = b.size();

    for(int i = 0; i < na; i++) {
        for(int j = 0; j < b[0].size(); j++) {
            for(int k = 0; k < nb; k++) {

            }
        }
    }
} */

void test3() {
    vector<int> v{1, 3, 8, 0, 0, 65, 67, 100, 200};
    int res = 1;
    // int max = 1;

    vector<int> dp(v.size(), 1);
    for(int i = 1; i < v.size(); i++) {
        if(v[i] > v[i - 1]) {
            dp[i] = dp[i - 1] + 1;
            // max = std::max(max, res);
            // cout << max << endl;
        }
        res = std::max(res, dp[i]);
    }
    cout << res << endl;

    for(int i = 0; i < v.size(); i++) {
        cout << dp[i] << endl;
    }
}

int getSum(vector<vector<int>>& v, int i, int j, int m) {
    int res = 0;
    for(int x = i; x < i + m; x++) {
        for(int y = j; y < j + m; y++) {
            res += v[x][y];
        }
    }
    return res;
}

// 1
vector<vector<int>> test4(vector<vector<int>> &v, int m) {
    int n = v.size();
    int newN = n - m + 1;
    vector<vector<int>> v2(newN, vector<int>(newN, 0));
    for(int i = 0; i < newN; i++) {
        for(int j = 0; j < newN; j++) {
            v2[i][j] = getSum(v, i, j, m);
        }
    }
    return v2;
}

// 2
int getOnes(int n) {
    int res = 0;
    for(; n; ) {
        res++;
        n = n & (n - 1);
    }
    return res;
}

// 3. longest uniq
int longestUniq(string& s) {
    int len = 1;
    int res = 1;
    int n = s.size();
    int pos = -1;
    vector<int> hash(256, -1);
    // for() {

    // }
    // 关键在查找重复的位置，
    for(int i = 0; i < n; i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
        // longest 
    }
    return res;
}

// 4. big or little
bool isLittle() {
    int i = 1;
    char c = *(char*)(&i);
    return c == 1 ? true : false;
}

// 5. aligned malloc
#if 0
void *align_malloc(size_t size, size_t alignment) {
    size_t offset = alignment - 1;
    size_t newSize = size + offset + sizeof(size_t);
    size_t* addr = (size_t *)malloc(newSize);
    size_t* newAddr = (addr + offset) & (~offset);
    *(newAddr - 1) = newAddr - addr;

    return (void*)newAddr;
}

void align_free(void* addr) {
    void* realAddr = (size_t*)addr - *(size_t*)(addr - 1);
    free(realAddr);
}
#endif

// 6. read4
int read4(char* buf4) {
    // read 4 bytes
    int n = 0;
    return n;
}

int readData(char* buf, int n) {
    int readChar = 4;
    int copiedChar = 0;
    char buf4[4];
    while(readChar == 4 && copiedChar < n) {
        readChar = read4(buf4);
        for(int i = 0; i < readChar; i++) {
            if(copiedChar == n) {
                return copiedChar;
            }
            buf[copiedChar++] = buf4[i];
        }
    }
    return copiedChar;
}

// 7. 二分查找
int binSearch(vector<int>& v, int target) {
    int left = 0, mid, right = v.size() - 1;
    while(left <= right) {
        // mid = (left + right) / 2;
        mid = left + (right - left) / 2;
        if(v[mid] == target) {
            return mid;
        }
        if(v[target] < v[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

// 8. remove ele
int removeVal(vector<int>& v, int val) {
    int left = 0;
    for(int right = 0; right < v.size(); right++) {
        if(v[right] != val) {
            v[left++] = v[right];
        }
    }
    return left;
}

// 9. memory move
int memMove(const void* des, const void* src, size_t n) {
    des = (unsigned int*)des;
    src = (unsigned int*)src;
    if(src > des) {
        // copy from front
        while(n--) {
            *des = *src;
            des++, src++;   
        }
    } else {
        // copy from end

    }

    int cpuSize = sizeof(size_t);
    int t1 = srcLen / cpuSize;
    int t2 = srcLen % cpuSize;

    size_t *d = newDst;
    size_t *s = src;

    for(int i = 0; i < t1; i++) {
        *d++ = *s++;    
    }

}

// 10. memcpy alignment
void* memcpyAlign(size_t align, void* dst, const void* src, size_t dstLen, size_t srcLen) {
    size_t offset = alignment - 1;
    newDst = (dst + offset) & ~(offset);

    if(dstLen - (newDst - dst) < srcLen) {
        return nullptr;
    }
    cpuSize = sizeof(size_t);
    size_t t1 = srcLen / cpuSize;
    size_t t2 = srcLen % cpuSize;

    size_t* d = newDst;
    size_t* src;

    for() {
        
    }
}


int main() {
    // vector<char> tasks = {'a', 'b', 'c', 'a', 'a', 'b', 'c'};
    // leastInterval(tasks, 2);

    // vector<char> nums{'x', 'b', 'a', 'c', 'b', 'a', 'z', 'x'};
    // topKFreq(nums, 3);
    // test();

    // cout << getOnes(15) << endl;

    // string s = "abacada";
    // cout << longestUniq(s) << endl;

    vector<int> v{1, 1, 2, 3, 4, 2, 1};
    cout << removeVal(v, 1) << endl;

    return 0;
}