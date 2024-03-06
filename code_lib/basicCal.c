
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

// c++ 版本
int calculate(char * s){
    char op = '+';
    long long cur = 0;
    stack<long long> st;

    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {   // 找出完整的整数
            cur = cur * 10 + s[i] - '0';
        }
        // (不是整数 + 不是空格) + 是字符结尾
        if((!isdigit(s[i]) && !isspace(s[i]) || (i + 1) == s.size())) {
            long long x;
            switch(op) {
                // 如果是+, -, 直接入栈
                case '+':
                    st.push(cur);
                break;
                case '-':
                    st.push(-cur);
                break;
                // 如果是*/，将栈里的内容pop出来操作。
                case '*':
                    x = st.top();
                    st.pop();
                    st.push(x * cur);
                break;
                case '/':
                    x = st.top();
                    st.pop();
                    st.push(x / cur);
                break;
            }
            op = s[i];     //very important
            cur = 0;
        }
    }

    int res = 0;
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}


// ============================================================================================================


// "2", "13", "+", "32", "76", "*"
// "14", "4", "*"

// failed
// "*", "32"
// "-", "+"
// "14", "4", "8"

int stack[1000] = {0};
int sp = -1;

void push(int val) {
    stack[++sp] = val;
}

int pop() {
    int val = stack[sp--];
    return val;
}

int isEmpty() {
    if(sp < 0) {
        return 1;
    }
    return 0;
}

int getCurNum(char* s) {
    int sum = 0;
    while (*s) {
        sum = sum * 10;
        sum += *s - '0';
        s++;
    }
    return sum;
}

int test(char* s[], int len, int* ret) {
    for(int i = 0; i < len; i++) {
        // 1. the first one is operator
        if(i == 0 && (isdigit(*s[i]) == 0)) {
            return -1;
        }

        // 2. cur: digit, pre->pre: digit
        if(isdigit(*s[i]) != 0 && i - 2 >= 0) {
            if(isdigit(*s[i - 2]) != 0) {
                return -1;
            }
        }
        
        // 3. cur: ope, pre: ope
        if(i > 0 && isdigit(*s[i]) == 0 && isdigit(*s[i - 1]) == 0) {
            return -1;
        }

        if(isdigit(*s[i]) != 0) {
            push(getCurNum(s[i]));
        } else {
            if(strcmp(s[i], "+") == 0) {
                push(pop() + pop());
            } else if(strcmp(s[i], "-") == 0) {
                push(-1 * pop() + pop());
            } else if(strcmp(s[i], "*") == 0) {
                push(pop() * pop());
            } else if(strcmp(s[i], "/") == 0) {
                push(pop() / pop());
            }
        }
    }

    int sum = 0;
    while(!isEmpty()) {
        sum += pop();
    }

    *ret = sum;

    return 0;
}


int main() {
    char* s[] = { "12", "36", "/" , "-"};
    int* ret = (int*)malloc(sizeof(int));
    test(s, sizeof(s) / sizeof(s[0]), ret);

    printf("%d\n", *ret);

    free(ret);

    return 0;
}