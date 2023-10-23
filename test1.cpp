
#include "test.hpp"

int test(vector<int> nums) {
    int j = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            nums[j++] = nums[i];
        }
    }
    return j;
}

vector<vector<int>> dp(a.size() + 1, vector<int> (b.size() + 1, 0));
dp[0][0] = 0;
for(int i = 1; i <= a.size(); i++) {
    for(int j = 1; j <= b.size(); j++) {
        if(a[i - 1] == b[j - 1]) {
            dp[i][j] = max(dp[i - 1][j - 1] + 1);
        }
        res = max(res, dp[i][j]);
    }
}
return res;


int dp_46(vector<int> nums) {
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }
    
    return res;
}


int main(void) {
    vector<int> nums = {1, 2, 2, 3, 4, 5};

    cout << test(nums) << endl;

    return 0;
}