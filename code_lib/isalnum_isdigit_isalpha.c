#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>



int main() {
    // 输入是字符！！！！  不是字符串！！！！！

    char x = '5';
    char y = 'a';
    char z = '+';
    int res;

    /* 
        isalnum: 
            数字和字母: return non-zero
            if not   : 0
     */
    printf("%d\n", isalnum(x));    // 返回值    非 0
    printf("%d\n", isalnum(y));    // 返回值    非 0
    printf("%d\n", isalnum(z));    // 返回值    等于0

    /* 
        isdigit: 
            数字  : return non-zero
            if not: 0
     */
    printf("%d\n", isdigit(x));    // 返回值    非 0
    printf("%d\n", isdigit(y));    // 返回值    等于0

    /* 
        isalpha:      
            a ~ z : return non-zero integer
            if not: return 0
     */
    printf("%d\n", isalpha(x));    // 返回值    等于0

    return 0;
}