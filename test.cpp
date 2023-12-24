


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

int longestUniqStr(string& s) {
    // unordered_map<char, int> map(256, -1);
    int map[256];
    for(int i = 0; i < 256; i++) {
        map[i] = -1;
    }

    int pos = -1;
    int len = 0;
    int res = 0;
    for(int i = 0; i < s.size(); i++) {
        pos = max(pos, map[i]);

    }

    cout << res << endl;
}

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

int main(void) {
    cout << rangeBitwiseAnd(5, 7) << endl;
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