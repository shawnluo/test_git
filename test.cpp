


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
    7. 
 */



int main(void) {
    // int x = 0b110;
    // string s = "1101.111";
    // double res = binaryFractionToDecimal(s);
    // cout << res << endl;

    // int2Bin(12);

    int m = 100;
    int n = 500;
    // const int *p = &m;
    // p = &n;
    // *p = 300;

    int* const p2 = &m;
    p2 = m;
    // *p2 = 14;

    cout << *p2 << endl;

    return 0;
}