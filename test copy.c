#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#if 0
int main(int argc, char** argv) {
    int aflag    = 0;
    int bflag    = 0;
    char* cvalue = NULL;
    int index;
    int c;

    int opterr = 0;
    char optopt;

    while ((c = getopt(argc, argv, "abc:")) != -1)
        switch (c) {
        case 'a': aflag = 1; break;
        case 'b': bflag = 1; break;
        case 'c': cvalue = optarg; break;
        case '?':
            if (optopt == 'c')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            return 1;
        default: abort();
        }

    printf("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);

    for (index = optind; index < argc; index++)
        printf("Non-option argument %s\n", argv[index]);
    return 0;
}

// #else
int main(int argc, char **argv)
{
  int i;
  int option;

  /* parse short options */

  while ((option = getopt(argc, argv, "bEnsTv")) != -1) {
    switch (option) {
    case 'b':
      puts("Put line numbers next to non-blank lines");
      break;
    case 'E':
      puts("Show the ends of lines as $");
      break;
    case 'n':
      puts("Put line numbers next to all lines");
      break;
    case 's':
      puts("Suppress printing repeated blank lines");
      break;
    case 'T':
      puts("Show tabs as ^I");
      break;
    case 'v':
      puts("Verbose");
      break;
    default:                          /* '?' */
      puts("What's that??");
    }
  }

  /* print the rest of the command line */

  puts("------------------------------");

  for (i = optind; i < argc; i++) {
    puts(argv[i]);
  }

  return 0;
}
#endif

#if 0
long long stack[100000] = {0};
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

int isOp(char* s) {
    if(strcmp(s, "+") == 0 || strcmp(s, "-") == 0 || strcmp(s, "*") == 0 || strcmp(s, "/") == 0)
        return 1;
        
    return 0;
}

void test() {
  long long curNum = 0;
    char operation = '+';
    int isOperation = 0;
    char* postfix[3] = {"6", "2", "+"};
    
    for(int i = 0; i < 3; i++) {
        char* s = (char*)postfix[i];
        
        if(strcmp(s, "+") == 0 || strcmp(s, "-") == 0 || strcmp(s, "*") == 0 || strcmp(s, "/") == 0) {
            isOperation = 1;
        } else {
            isOperation = 0;
            char* p = s;
            while(*p) {
                curNum = curNum * 10 + *p - '0';
                p++;
            }
        }
        
        if(i >= 2) {
            if((!isOperation) && isOp(postfix[i - 1]) == 0 && isOp(postfix[i - 2]) == 0) {
                return;
            }
        }

        if(i == 1) {
            if((!isOperation) && isOp(postfix[i - 1]) == 0) {
                return;
            }
        }

        if(i >= 2) {
            if((!isOperation) && isOp(postfix[i - 1]) == 0 && isOp(postfix[i - 2]) == 1) {
                return;
            }
        }
        
        if(isOperation) {
          if(strcmp(postfix[i], "+")) {
              push(curNum);
          } else if(strcmp(postfix[i], "-")) {
              push(-curNum);
          } else if(strcmp(postfix[i], "*")) {
              push(pop() * curNum);
          } else if(strcmp(postfix[i], "/")) {
              push(pop() / curNum);
          }
        }



        //     switch(operation) {
        //         case '+':
        //             push(curNum);
        //             break;
        //         case '-':
        //             push(-curNum);
        //             break;
        //         case '*':
        //             push(pop() * curNum);
        //             break;
        //         case '/':
        //             if(strcmp(postfix[i - 1], "0")) {
        //                 return;
        //             }
        //             push(pop() / curNum);
        //             break;                    
        //     }
        // }
        operation = postfix[i];
        curNum = 0;
    }
    
    int res = 0;
    while(!isEmpty()) {
        res += pop();
    }
    // *result = res;
    printf("%d\n", res);

}

#endif

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