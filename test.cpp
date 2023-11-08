
#include "test.hpp"


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
        if(isdigit(*s)) {
            curNum = curNum * 10 + *s - '0';
        }

        if((!isdigit(*s) && !isspace(*s)) || *(s + 1) =='\0') {
            //last operation! Not current operation!
            switch(operation) {
                case '+':
                    push(curNum);
                    break;
                case '-':
                    push(-curNum);
                    break;
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