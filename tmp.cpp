
#include "test.hpp"


int dp_12(vector<int>& weight, vector<int>& value, int BAG) {
    vector<int> dp(weight.size() + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}

int Add(int num1, int num2) {
    int sum, carry = 1;
    while(carry) {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    return sum;
}

int main(void) {
    cout << Add(1, -5) << endl;

    return 0;
}