#include <stdio.h>
#include "../test.hpp"

// To execute C, please define "int main()"

/* return the 2's complement of an input integer
   - without using arithmetic ops (+, -, *, /).   */

/*
1 (0x0001) <-> -1 (0xFFFF)
2 (0x0002) <-> -2 (0xFFFE)
3 (0x0003) <-> -3 (0xFFFD)
*/

/*
    0x0001 -> 0xFFFF  ~(x + 1)
    0xFFFF -> 0x0001  ~(x + 1)
 */

/* 
    解题思路1：
    首先看十进制是如何做的： 5+7=12，三步走

    第一步：相加各位的值，不算进位，得到2。

    第二步：计算进位值，得到10. 如果这一步的进位值为0，那么第一步得到的值就是最终结果。

    第三步：重复上述两步，只是相加的值变成上述两步的得到的结果2和10，得到12。

    同样我们可以用三步走的方式计算二进制值相加： 5-101，7-111

    第一步：相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111。

    第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。

    第三步重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1。

    继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。
 */

int getComplementOfTwo(int num) {
    num      = ~num;
    int num2 = 1;
    while (num2) {
        int tmp = (num ^ num2);
        num2    = (num2 & num) << 1;
        num     = tmp;
    }
    return num;
}

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
    int res = getComplementOfTwo(2);
    cout << res << endl;

    num = 2;
    res = add(num, 1);
    cout << res << endl;

    return 0;
}