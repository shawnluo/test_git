#include "common.h"
#include "test.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int break_int(int n) {
    int dp[n + 1]; //the maximum of breaking n multiple
    for(int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i <= n; i++) {
        for(int j = 0; j < i; j++)  {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }
    printf("%d\n", dp[n]);
    return dp[n];
}



void test() {
    char str[80] = "This is - www.tutorialspoint.com - website";
    const char s[2] = "-";
    char *token;

    token = strtok(str, s);
    printf(" %s\n", token);
    while(token != NULL) {
        printf(" %s\n", token);
        token = strtok(NULL, s);
    }
}

//TODO break_int()


int main(void) {
    //break_int(8);
    test();

    return 0;
}