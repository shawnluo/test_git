#include "common.h"
#include "test.h"


/*  0 1 1 2 3 5
    i       : 
    dp[i]   : fib of i
*/
void fib(int num) {
    int dp[num];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 0; i < num; i++) {
        dp[i] =  dp[i - 1] + dp[i - 2];
    }
}

void ladder(int num) {
    int dp[num + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= num; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

void ladder_ext(int num) {

}

int main(void) {
    fib(5);

    return 0;
}