#include "common.h"
#include "test.h"

信号量实现 多生产者 多消费者问题
qsort 自定义
1       // 1 calculator
9       // 2. read4
1       // 3. kmp
5       // 4. longest no uniq string
8       // 5. quick sort
9       // 6. rotate mat
9       // 7. spiral square
9       // 8. little ending?
9       // 9. ones in a interger
5.      // 10. bit manipulate
            // 1. set/clear from m to n
            // 2. set from m, follwing n bits
            // 3. swap x and y without tmp: 
                // 1. think this way for every bit, x = 0, y = 1, x = x ^ y = 0 ^ 1 = 1
                // 2. y = x ^ y = 1 ^ 1 = 0
                // 3. now x swapped with y.
                // 4. swap 2 numbers can be treat as multiple bits just explained in step 1, 2, 3
// 11. find island
// 12. robot clean
// 13. shortest path
8       // 14. int to Roman
8       // 15. Roman to int
// 16. blur pixels
// 17. delete extra spaces in a string.
// 18. 小数转二进制
// 19. 二进制转小数
// 20. meeting room
5.      // 21. leetcode201. Bitwise AND of Numbers Range
6.      // application with interrupt
5       // 21. leetcode201. Bitwise AND of Numbers Range

class Solution {
    public int calculate(String s) {
        if (s == null || s.isEmpty()) return 0;
        int length = s.length();
        int currentNumber = 0, lastNumber = 0, result = 0;
        char operation = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s.charAt(i);
            if (Character.isDigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!Character.isDigit(currentChar) && !Character.isWhitesp     ace(currentChar) || i == length - 1) {
                if (operation == '+' || operation == '-') {
                    result += lastNumber;
                    lastNumber = (operation == '+') ? currentNumber : -currentNumber;
                } else if (operation == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (operation == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
}


int main(void) {
    // break_int(8);
    //int res = validWordAbbreviation("internationalization", "i12iz4n");
    //printf("%d\n", res);

    quicksort();

    return 0;
}