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

int main(void) {
    string s = "abxx";
    string t = "abcxa";

    cout << ransom4(s, t) << endl;

    return 0;
}