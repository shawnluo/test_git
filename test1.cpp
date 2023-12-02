
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

#include <iostream>
#include <string>


int dp_12(vector<int>& weight, vector<int>& value, int BAG) {
    int size = weight.size();
    vector<int> dp(BAG + 1, 0);

    for(int i = BAG; i >= 0; i--) {
        cout << i << "\t";
    }
    cout << endl;
    cout << endl;

    for(int i = 0; i < size; i++) {
        // for(int j = BAG; j >= weight[i]; j--) {
        for(int j = BAG; j >= 0; j--) {
            if(j < weight[i]) {
                cout << 0 << "\t";    
            } else {
                // j = 1    dp[1] = dp[1 - 1] + 15 = 15
                // j = 2    dp[2] = dp[2 - 1] + 15 = 30

                // j = 2    dp[2] = dp[2 - 1] + 15 = 15     dp[1] = 0
                // j = 1    dp[1] = dp[1 - 1] + 15 = 15     dp[0] = 0
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                cout << dp[j] << "\t";
            }
        }
        cout << endl;
    }
    return dp[BAG];
}

bool dp_13(vector<int>& nums) {
    int n = nums.size();
    int BAG = accumulate(nums.begin(), nums.end(), 0);
    
    if (BAG % 2) return 0;

    vector<int> dp(BAG + 1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = BAG; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    return dp[BAG] == (BAG % 2) ? true : false;
}

int dp_16(vector<int>& nums, int s) {
    /* 
        pos + neg = sum
        pos - neg = s
        pos = (sum + s) / 2
     */
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int BAG = (sum + s) / 2;

    vector<int> dp(BAG + 1, 0);
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        for(int j = BAG; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[BAG];
}

vector<vector<int>> res;
vector<int> path;
int sum = 0;
void bt(vector<int>& nums, int s, int pos) {
    if(sum > s) return;
    if(sum == s) {
        res.push_back(path);
        return;
    }
    for(int i = pos; i < nums.size(); i++) {
        sum += nums[i];
        path.push_back(nums[i]);
        bt(nums, s, pos);
        sum -= nums[i];
        path.pop_back();
    }
    
}

int main() {
    vector<int> weight = {1, 3, 4};
    // vector<int> value = {15, 20, 30};
    // int BAG = 15;
    // dp_12(weight, value, BAG);

    cout << dp_13(weight) << endl;

    return 0;
}