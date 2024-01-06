#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

class Solution {
public:
    bool is_Valid(int n) {
        vector<int> dp(n + 1, 0); // dp[i]: the value when fill bag i

        for (int i = 2; i <= 3; i++) {
            for (int j = 0; j <= n; j++) {
                if (j >= i) dp[j] = max(dp[j], dp[j - i] + i);
            }
        }
        cout << dp[n] << endl;
        return dp[n] == n ? true : false; 
    }

    int MinOfOperations(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 2; i <= 3; i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[j - i] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - i] + 1);
                }
            }
        }
        // cout << dp[n] << endl;
        return dp[n];
    }

    int minOperations(vector<int>& nums) {
        unordered_map<int, int> uMap;
        int n     = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // cout << i << endl;
                uMap[i]++;
                // cout << uMap[i] << endl;                
        }

        for (auto it = uMap.begin(); it != uMap.end(); it++) {
            if (!is_Valid(it->second)) {
                return -1;
            }
        }
        cout << 1111 << endl;
        for (auto it = uMap.begin(); it != uMap.end(); it++) {
            cout << it->first << endl;
            count += MinOfOperations(it->second);
        }

        return count;
    }
};

int main() {
    vector<int> nums = { 2, 3, 3, 2, 2, 4, 2, 3, 4 };
    Solution s;
    cout << s.minOperations(nums) << endl;

    return 0;
}