#include "test.hpp"

/*
    给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
    判断第一个字符串 ransom 能不能全部由第二个字符串 magazines 里面的字符构成。
    如果可以构成，返回 true ；
    否则返回 false。
    (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，
    组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。

    注意：是全部由magazines里面的字符构成
*/
bool ransom(string s, string t) { // s: ransom  t: magazine
    int hash[256] = {0};
    for(auto x : t) {
        hash[x]++;
    }
    for(auto x : s) {
        if(--hash[x] < 0) {
            return false;
        }
    }
    return true;
}

// 求s是否由t中的字符构成？ t中的字符可以重复被使用  
// example:   s - abca  t - abcdx  -> true
bool ransom2(string s, string t) {
    unordered_set<char> set(t.begin(), t.end());

    for(auto x : s) {
        if(set.find(x) == set.end()) {
            return false;
        } 
    }
    return true;
}

bool ransom3(string s, string t) {
    unordered_set<char> set(t.begin(), t.end());

    for(auto x : s) {
        if(set.find(x) == set.end()) {
            return false;
        }
    }
    return true;
}

bool ransom4(string s, string t) {
    unordered_map<char, int> unmap;
    for(auto x : t) {
        unmap[x]++;
    }

    unordered_map<char, int>::iterator it;
    for(it = unmap.begin(); it != unmap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    std::for_each (
        unmap.begin(), 
        unmap.end(), 
        [](std::pair<char, int> p) {
            cout << p.first << " :: " << p.second << endl;
        }
    );
    return true;
}




vector<int> interSection(vector<int> a, vector<int> b) {
    unordered_set<int> set(b.begin(), b.end());
    unordered_set<int> res;

    for(auto x : a) {
        if(set.find(x) != set.end()) {
            res.insert(x);
        }
    }
    return vector<int>(res.begin(), res.end());
}


int FourSum(vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    // unmap(sum_ab, num);
    unordered_map<int, int> unmap;
    for(auto x : a) {
        for(auto y : b) {
            unmap[x + y]++;
        }
    }

    int count = 0;

    for(auto x : c) {
        for(auto y : d) {
            if(unmap.find(-x-y) != unmap.end()) {
                count += unmap[-x-y];
            }
        }
    }
    return count;
}

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> res;
    // 1. sort
    sort(nums.begin(), nums.end());
    // 2. for loop travesal - p1
    // 3. pointer 2 from p1 + 1
    // 4. pointer 3 from nums.end()

    int size = nums.size();
    for(int i = 0; i < size; i++) {
        if(nums[i] > 0) {
            break;
        }
        // sum += nums[i];
        // buf.push_back(nums[i]);
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int j = i + 1;
        int k = size - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                res.push_back({nums[i], nums[j], nums[k]});
                if(j < k && nums[j] == nums[j - 1]) {
                    j++;
                } 
                if(j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
                j++, k--;
            }
        }
    }
    return res;
}

// Encharge ai

void getNext(int *next, string s) {
    next[0] = 0;
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int kmp(string s, string t) {
    int j = 0;
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

int partition(vector<int>& nums, int start, int end) {
    int j = start - 1;
    for(int i = start; i < end; i++) {
        if(nums[i] < nums[end]) {
            swap(nums[i], nums[++j]);
        }
    }
    swap(nums[++j], nums[end]);
    return j;
}

int binSearch(vector<int>& nums, int start, int end, int k) {
    if(start < end) {
        int pivot = partition(nums, start, end);
        if(k < pivot) {
            binSearch(start, pivot - 1);
        } else if(k > pivot) {
            binSearch(pivot + 1, end);
        } else {
            return nums[k];
        }
    }
}

int kth(vector<int> nums, int k) {
    return binSearch(nums, 0, nums.size() - 1);
}

int kth_heap(vector<int> nums, int k) {
    priority_que<int> heap;
    for(auto x : nums) {
        heap.push(-x);
        if(heap.size() > k) {
            heap.pop();
        }
    }
    return -heap.top();
}

void matRotate(vector<vector<int>>& mat) {
    int size = mat.size();

    for(int i = 0; i < size / 2; i++) {
        for(int j = i; j < size - i; j++) {
            int save = mat[i][j];
            mat[i][j] = mat[j][size - i - 1];
            mat[j][size - i - 1] = mat[size - i - 1][size - j - 1];
            mat[size - i - 1][size - j - 1] = mat[size - j - 1][i];
            mat[size - j - 1][i] = save;
        }
    }
}

void spiral(int n) {
    int half = n / 2;

    int startX = 0;
    int startY = 0;
    int offset = 1;
    int count = 1;

    vector<vector<int>> mat(n, vector<int>(n, 0));

    while(half-- > 0) {
        int x = startX;
        int y = startY;
        for(; y < n - offset; y++) mat[x][y] = count++;
        for(; x < n - offset; x++) mat[x][y] = count++;
        for(; y > startY; y--) mat[x][y] = count++;
        for(; x > startX; x--) mat[x][y] = count++;

        startX++, statY++, offset++;
    }
}

void delExtraSpaces(string& s) {
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            if(j != 0) {
                s[j++] = ' ';
            }
            while(i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }
    }
    s.resize(j);
}

int main(void) {
    vector<int> num{-2, 1, 1, 5, -6};
    vector<vector<int>> res = threeSum(num);

    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    
    // vector<int> nums1{1, 2, 4, 3, 5};
    // vector<int> nums2{1, 2, 3, 5};

    // vector<int> res = interSection(nums1, nums2);
    // for(auto x : res) {
    //     cout << x << endl;
    // }

    // int target = 4;
    // vector<int> res = twoSum2(nums, target);
    // cout << res[0] << " " << res[1] << endl;

    // test();

    // string s = "abxx";
    // string t = "abcxa";

    // cout << ransom4(s, t) << endl;

    return 0;
}