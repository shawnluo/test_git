


#include "test.hpp"
#include <thread>

using namespace std;
 
/* TODO
    1. 🔥   find island
    2. 🔥   decimal to bin c/c++
    3. bin to decimal c/c++
    4. blur
    5. memcpy
    6. memcpy align
    7. delete extra spaces in a string
    8. robbing houses
    9. rangeBitwiseAnd
 */

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, pair<int, int>> map(256);
        for(int i = 0; i < 256; i++) {
            map[i].first = -1;
            map[i].second = -1;
        }

        int pos = -1;
        int len = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            pos = max(pos, map[s[i]].first);
            len = len, i - pos;
            res = max(res, len);
            if(map[s[i]].second == -1) {
                map[s[i]].first = i;
            } else if(map[s[i]].second == -1) {
                map[s[i]].second = i;
            } else {
                map[s[i]].first = map[s[i]].second;
                map[s[i]].second = i;
            }
        }
        return res;
    }
};


int dp_29(vector<int> nums) {
    return 0;
}

// "   ab cd     x y cc  exit   "
void delExtraSpaces(string& s) {
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ' && j > 0) {
            s[j++] = ' ';
        }
        for(; s[i] != ' ' && s[i] != '\0'; i++) {
            s[j++] = s[i];
        }
    }
    s.resize(j);
}

int rangeBitwiseAnd(int m, int n) {
    // 5, 7
    // 101, 110, 111
    int count = 0;
    for(; m != n; m >>= 1, n >>= 1) {
        count++;
    }

    return m <<= count;
}

int findPos(string s) {
    int len = s.size();
    char third = s[len - 1];
    char second = -1;

    for(int i = len - 2; i >= 0; i--) {
        if(second != -1 && s[i] != second && s[i] != third) {
            return i;
        }
        if(second == -1 && s[i] != third) {
            second = s[i];
        }
    }
    return -1;
}

int lengthOfLongestSubstringTwoDistinct(string s) {
    set<int> Set;
    int pos = -1;
    int len = 0;
    int ret = 0;
    for(int i = 0; i < s.size(); i++) {
        /*  1. 算上当前char，有多少个char
                1). 如果len > 2, 
                    则计算只剩2个元素的pos，
                    长度: i - pos
                    如何确定pos? 
                        1）初始化为-1。 
                        2）pos = i - 1, pos << x 直到 s[x] != s[pos]
                2). else, nothing
         */
        Set.insert(s[i]);
        if(Set.size() > 2) {
            // find pos
            pos = findPos(s.substr(0, i + 1));
            cout << "i = " << i << ", pos = " << pos << endl;
            Set.erase(s[pos]);
            len = i - pos;
            ret = max(ret, len);
        } else if(Set.size() == 2){
            len = i - pos;
            ret = max(ret, len);
        }
    }
    if(pos == -1) {
        ret = s.size();
    }
    return ret;
}


int hIndex(vector<int>& citations) {


    priority_queue<int, vector<int>, greater<int>> pq(citations.begin(), citations.end());

    // while(pq.size() != 0) {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }
    // return 0;
    // sort(citations.begin(), citations.end());
    int ret = 0;
    for(int i = 0; i < citations.size(); i++) {
        ret = pq.size();
        cout << ret << endl;
        if(pq.size() < i + 1) {
            break;
        }
        // cout << pq.top() << endl;


        while(pq.top() <= i) {
            pq.pop();
        }
    }
    return ret;
}

void removeExtraSpaces(string& s) {
    int fast = 0;   // 在老的字符串中travel
    int slow = 0;   // 指向新的字符串

    for(fast = 0; fast < s.size(); fast++) {
        // 如果遇到空格，fast就向前走越过空格

        // 否则，遇到了非空格
        if(s[fast] != ' ') {
            // 如果是开头，那么新字符串就不用保留空格

            if(slow != 0) {     // 如果不是开头，那么新字符串留一个空格
                s[slow++] = ' ';
            }
            while(fast < s.size() && s[fast] != ' ') { // 不是空格， 那么就拷贝到新字符串中
                s[slow++] = s[fast++];
            }
            // fast 现在指向了空格
        }
    }
    s.resize(slow);
}

// void removeExtraSpaces(string& s) {
//         int j = 0;
//         int n = s.size();
//         for(int i = 0; i < n; i++) {
//             if(s[i] != ' ') {
//                 if(j != 0) {
//                     s[j++] = ' ';
//                 }
            
//                 while(i < n && s[i] != ' ') {
//                     s[j++] = s[i++];
//                 }
//             }
//         }
//         s.resize(j);
//     }

int lengthOfLastWord(string& s) {
    removeExtraSpaces(s);

    int n = s.size();
    int ret = 0;
    for(int i = n - 1; i >= 0 && s[i] != ' '; i--) {
        ret++;
    }
    return ret;
}

int lengthOfLastWord_x(string s) {
    int n = s.size();
    int i = n - 1;
    int count = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] != ' ') {
            while(i >= 0 && s[i] != ' ') {
                count++;
                i--;
            }
            return count;
        }
    }
    return 0;
}

class compare {
public:
    bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs) {
        return lhs.second < rhs.second;
    }
};

string test(string& s) {
    unordered_map<char, int> uMap;
    for(int i = 0; i < s.size(); i++) {
        uMap[s[i]]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
    // priority_queue<pair<char, int>, vector<pair<char, int>>> pq;

    for(auto it = uMap.begin(); it != uMap.end(); it++) {
        pq.push(*it);
    }

    string res;
    for(; pq.size() != 0; pq.pop()) {
        // cout << pq.top().first << " : " << pq.top().second << endl;
        for(int i = 0; i < pq.top().second; i++) {
            // cout << pq.top().first;
            res.push_back(pq.top().first);
        }
    }
    // reverse(res.begin(), res.end());

    return res;
}

class compare_xx {
public:
    bool operator() (const pair<char, int>& lhs, const pair<char, int>& rhs) {
        return lhs.second < rhs.second;
    }
};

void test2() {
    string s = "bbaccca";
    unordered_map<char, int> uMap;
    int n = s.size();
    for(auto it : s) {
        uMap[it]++;
    }
    for(auto it : uMap) {
        cout << it.first << " : " << it.second << endl;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
    for(auto it = uMap.begin(); it != uMap.end(); it++) {
        pq.push(*it);
    }
    string ret;
    for(; pq.size() != 0; pq.pop()) {
        for(auto it = 0; it < pq.top().second; it++) {
            ret.push_back(pq.top().first);
        }
    }
    cout << ret << endl;
}

void test3() {
    list<int> myList = {1, 2, 3};
    myList.push_front(5);

    for(auto it : myList) {
        cout << it << endl;
    }
}

void test4() {
    vector<int> v = {1, 2, 3};
    cout << v.size() << endl;
}

void test5() {
    string s = "MCMXCIV";
    set<pair<char, int>> v;
    v.insert(pair{'I', 1});
    v.insert(pair{'V', 5});
    v.insert(pair{'X', 10});
    v.insert(pair{'L', 50});
    v.insert(pair{'C', 100});
    v.insert(pair{'D', 500});
    v.insert(pair{'M', 1000});

    int n = s.size();

    // "MCMXCIV" 1000 + 900 + 90 + 4
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(s[i + 1] > s[i]) {
            cout << v[s[i]].second << endl;
            res -= v[s[i]].second;
        } else {
            res += v[s[i]].second;
        }
    }
    cout << res << endl;
}


int main(void) {
    test5();

    // string s1 = "aAbb";
    // string s2 = "tree";
    // string s3 = "aabbac";
    // test2();

    // test3();

    // string res = test(s);
    // cout << test(s1) << endl;
    // cout << test(s2) << endl;
    // cout << test(s3) << endl;
    // string s = " aaa bbbx s   h  ";
    // string s = "aaa xx";
    // int res = lengthOfLastWord_x(s);
    // cout << res << endl;

    // cout << "xxx" << res << "xxx" << endl;

    // vector<int> nums = {3, 0, 6, 1, 5}; // 0 1 3 5 6
    // int res = hIndex(nums);
    // cout << res << endl;

    // cout << rangeBitwiseAnd(5, 7) << endl;

    // int x = 0b110;
    // string s = "1101.111";
    // double res = binaryFractionToDecimal(s);
    // cout << res << endl;

    // int2Bin(12);

    // string s = "   ab cd     x y cc  exit   ";
    // delExtraSpaces(s);
    // cout << "OOO" << s << "OOO" << endl;

    return 0;
}