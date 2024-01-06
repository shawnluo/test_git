
#include "test.hpp"

#include <semaphore.h>
#include <unistd.h>
using namespace std;


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

int dp(vector<int> nums, int BAG) {
    int n = nums.size();
    vector<int> dp(BAG + 1, INT_MAX);
    // dp[i]: 凑成i，需要最少多少个
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= BAG; j++) {
            if(dp[j - nums[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);
        }
    }
    return dp[BAG];
}

bool dp_1(vector<int> nums, int BAG) {
    int n = nums.size();
    vector<int> dp(BAG + 1, 0);
    // dp[j]: 放入i后，背包的最大值重量

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j >= nums[i])
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    cout << dp[BAG] << endl;
    return dp[BAG] == BAG ? true : false;
}

bool isValid(int n) {
    vector<int> dp(n + 1, 0);   // dp[i]: the value when fill bag i 

    for(int i = 2; i <= 3; i++) {
        for(int j = 0; j <= n; j++) {
            if(j >= i)
                dp[j] = max(dp[j], dp[j - i] + i);
        }
    }

    cout << dp[5] << endl;
    return dp[n] == n ? true : false;
}

void test() {
    unordered_map<int, int> unmap;
    unmap[1] = 111;
    unmap[2] = 222;
    unmap[3] = 333;

    pair<int, int> p;
    for(auto it = unmap.begin(); it != unmap.end(); it++) {
        cout << it->second << endl;
    }
}

int main(void) {
    isValid(5);

    // vector<int> nums{2, 3};
    // bool res = dp_1(nums, 10);
    // cout << res << endl;

    // vector<int> nums{2, 3};
    // int res = dp(nums, 10);
    // cout << res << endl;

    return 0;
}