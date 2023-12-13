#include "common.h"
#include "test.h"


1 // 1 calculator
9 // 2. read4
1 // 3. kmp
// 4. longest no uniq string
// 5. quick sort
// 6. rotate mat
// 7. spiral square
// 8. little ending?
// 9. ones in a interger
// 10. bit manipulate
// 11. find island
// 12. robot clean
// 13. shortest path
8 // 14. int to Roman
8 // 15. Roman to int
// 16. blur pixels
// 17. delete extra spaces in a string.
// 18. 小数转二进制
// 19. 二进制转小数
// 20. meeting room
5. // 21. leetcode201. Bitwise AND of Numbers Range

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