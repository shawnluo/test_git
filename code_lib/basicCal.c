
/*
227. Basic Calculator II
Medium
5.9K
762
company
Facebook
company
Microsoft
company
Bloomberg
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/

long long stack[3000000] = {0};
int sp = -1;

void push(int data) {
    stack[++sp] = data;
}

int pop() {
    return stack[sp--];
}

int isEmpty() {
    return sp == -1 ? 1 : 0;
}

int calculate(char * s){
    char operation = '+';
    long long curNum = 0;
    while(*s) {
        if(isdigit(*s)) {   // 找出完整的整数
            curNum = curNum * 10 + *s - '0';
        }

        // (不是整数 + 不是空格) + 是字符结尾
        if((!isdigit(*s) && !isspace(*s)) || *(s + 1) =='\0') {
            //last operation! Not current operation!
            switch(operation) {
                // 如果是+, -, 直接入栈
                case '+':
                    push(curNum);
                    break;
                case '-':
                    push(-curNum);
                    break;
                // 如果是*/，将栈里的内容pop出来操作。
                case '*':
                    push(pop() * curNum);
                    break;
                case '/':
                    push(pop() / curNum);
                    break;
            }
            operation = *s;     //very important
            curNum = 0;
        }
        s++;
    }

    int res = 0;
    while(!isEmpty()) {
        res += pop();
    }
    return res;
}