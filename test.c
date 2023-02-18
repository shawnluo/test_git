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


//TODO knapsack
/*
dp[i][j]  
1. i       item[0, i], 
2. j       knapsack cap
3. dp[][]  most value

dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])
*/

void knapsack() {
    int knapsack = 100; //knapsack cap
    int weight[5] = {1, 76, 5, 18, 7};
    int value[5] = {10, 65, 91, 6, 18};
    int size = sizeof(weight) / sizeof(weight[0]);
    int dp[size][size + 1];
    int i, j;

    for(j = weight[0]; j <= knapsack; j++) {
        dp[0][j] = value[0];
    }

    for(i = 1; i < size; i++) {
        for(j = 0; j <= knapsack; j++) {
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    printf("%d\n", dp[size - 1][size]);
}

//TODO 
/*
    a1b2c3a8c6 -> a9b2c9
*/

void print_hash(int hash[], int size) {
    for(int i = 0; i < 256; i++) {
        printf("%d, ", hash[i]);
    }
}

void convert_string(void) {
    char *s = "a1b2c3a8c6";
    //1. using hash table to store the number of character
    //2. go throught hash[256] to store char with number

    int hash[256] = {0};
    int size = strlen(s);
    int sum = 0;
    int save = 0;
    int i, j;
    for(i = 0; i < size; ) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            save = i;
            i++;
            sum = 0;
            while(s[i] >= '0' && s[i] <= '9') {
                sum += sum * 10 + s[i] - '0';
                i++;
            }
            hash[s[save]] += sum;
        }
    }
    
    //print_hash(hash, 256);

    char res[1000] = {0};
    char c_tmp[1000] = {0};
    for(i = 0; i < 256; i++) {
        if(hash[i]) {
            sprintf(c_tmp, "%c", i);
            printf("%s\n", c_tmp);
            strcat(res, c_tmp);
            sprintf(c_tmp, "%d", hash[i]);
            printf("%s\n", c_tmp);
            strcat(res, c_tmp);
        }
    }

    printf("%s\n", res);
}

int main(void) {
    //break_int(8);
    convert_string();

    return 0;
}