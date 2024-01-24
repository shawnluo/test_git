#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

#include <cmath>
#include <iostream>


/*
  a ^ b 计算出2个加数二进制下每一位的本位
  a & b 计算出2个加数二进制下每一位的进位
  (a & b) << 1 进位做进位逻辑，也就是 * 2
 */
int add(int a, int b) {
    while (b != 0) {
        int carry = a & b; // 计算 进位
        a ^= b;            // 计算 本位
        b = (unsigned)carry << 1;
    }
    return a;
}

int main() {
    int num = 2;
    int res = add(num, 1);
    cout << res << endl;

    return 0;
}