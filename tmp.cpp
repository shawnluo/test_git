
#include "test.hpp"

// "aabaabaafa" 0, 1
// "aaaba" 0, 1

// TODO
// 1. kmp
// 2. pixels blur
/* 
  0 0 0 0 0 0
  0 1 2 1 1 0
  0 2 3 4 1 0
  0 3 4 6 5 0
  0 1 2 3 1 0
  0 0 
 */
void padding(vector<vector<int>>& v, vector<vector<int>>& newMat, int m) {
    int n = v.size();
    int size = m / 2 * 2 + n;
    cout << "v.size(): " << n << endl;
    cout << "size: " << size << endl;
    newMat.resize(size, vector<int>(size));
    int loop = m / 2;
    int startX = 0;
    int startY = 0;
    int offset = 1;
    // while(loop--) {
    //     int x = startX;
    //     int y = startY;
    //     for(; y < size - offset; y++) newMat[x][y] = 1;
    //     for(; x < size - offset; x++) newMat[x][y] = 1;
    //     for(; y > startY; y--) newMat[x][y] = 1;
    //     for(; x > startX; x--) newMat[x][y] = 1;
    //     startX++;
    //     startY++;
    //     offset++;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            newMat[i + m / 2][j + m / 2] = v[i][j];
        }
    }
}

int getSum(vector<vector<int>>& v, int x, int y, int m) {
    int sum = 0;
    for(int i = x; i <= x + m; i++) {
        for(int j = y; j <= y + m; j++) {
            sum += v[i][j];
        }
    }
    return sum;
}

void blurPixels(vector<vector<int>>& v, int m) {
    // 1. padding
    vector<vector<int>> newMat;
    padding(v, newMat, m);
    showMeV2(newMat);

    vector<vector<int>> res;

    // 2. get sum
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            res[i][j] = getSum(newMat, m);
        }
    }
}

int main(void) {
    blurPixels(mat, 3);
    // showMeV2(mat);
    
    return 0;
}

// void getNext(string& s, int* next) {
//     next[0] = 0;
//     int j = 0;
//     for(int i = 1; i < s.size(); i++) {
//         while(j > 0 && s[i] != s[j]) {
//             j = s[j - 1];
//         }
//         if(s[i] == s[j]) {
//             j++;
//         }
//         next[i] = j;
//     }
// }

// int mystrstr(string& s, string& t) {
//     int next[t.size()];
//     getNext(t, next);

//     int j = 0;
//     for(int i = 0; i < s.size(); i++) {
//         while(j > 0 && s[i] != t[j]) {
//             j = next[j - 1];
//         }

//         if(s[i] = t[j]) {
//             j++;
//         }
//         if(j == t.size()) {
//             return i - t.size() + 1;
//         }
//     }
//     return -1;
// }

// int main(void) {
//     string s = "abcde";
//     string t = "bc";
//     int res = mystrstr(s, t);
//     cout << res << endl;

//     return 0;
// }