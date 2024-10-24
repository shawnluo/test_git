#include "../test.hpp"
#include <stdio.h>


int add(int x, int y) {
    int c = 0;
    int s = 0;

    /* 
        将两个数不进位相加之后（异或操作），剩下的任务则是处理进位的问题：
            将不进位的和视为x，将进位左移一位后视作y。
            循环直到被左移一位的进位是0为止。
     */

    while(y) {
        c = x & y;  // carry
        s = x ^ y;  // sum
        x = s;      // 将sum   赋给 x
        y = c << 1; // 将carry 赋给 y
    }

    cout << s << endl;
    return s;
}

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
    循环 {
        先算出不计入进位的加法（半加），   - 用异或
        然后算出所有的进位，然后将进位左移一位                   - 用与
        半加 + 左移后的进位，
    }直到进位为0
 */

// 不用加减乘除实现加法(用位运算)
int Add(int num1, int num2) {
    int sum, carry;
    do {    // 也可以将carry初始化为1， 用while(carry){}的形式
        // 1.各位相加，不产生进位(3(011)+2(010)-->1(001))   - EWxclusive or (xor)
        sum = num1 ^ num2;

        // 2.找到要加的进位数(3(011)&2(010)-->1(010)<<1-->4(100))
        carry = (num1 & num2) << 1; // 将进位左移一位

        // 3.将前两步的值相加，但是相加不能用加法，重复前面两个步骤，直到不产生进位
        // 第二步的carry值为0，它们的和必然是sum的值
        num1 = sum;
        num2 = carry;

    } while (carry != 0); // 结束条件是不产生进位

    return num1;
}


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


// 求补码 - 取反，然后加一。但是不用 +-x/，用关系运算符完成
int getComplementOfTwo(int num) {
    num      = ~num;
    int num2 = 1;
    while (num2) {
        int tmp = (num ^ num2);
        num2    = (num2 & num) << 1;

        num = tmp;
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