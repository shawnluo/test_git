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


/*
    n   items
    w   the weight which bagpack can take
    weight[i]   ->  value[i]

    dp[i][j]    max value, if pick from item[0, i], put into backpak j
*/
int bagpack(int weight[], int value[], int n, int w) {
    //dp[i] the max weight which pick form item[0, i]
    int dp[n];
    dp[0] = 
    for(int i = 0; i <= n; i++) {
        dp[i] = max(dp[i - 1] + weight[i], dp[i]);
    }

    return dp[n];
}


char * addBinary(char * a, char * b){
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char * output = (char *)malloc(sizeOutput + 1);
    int sum = 0;
    
    output[sizeOutput] = '\0';
    
    while(sizeA > 0 || sizeB > 0 || sum > 0) {
        
        if(sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if(sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}


int main(void) {
    break_int(8);

    return 0;
}