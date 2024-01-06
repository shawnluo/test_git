
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool is_Valid(int n) {
    vector<int> dp(n + 1, 0);   // dp[i]: the value when fill bag i 
    for (int i = 2; i <= 3; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= i)
                dp[j] = max(dp[j], dp[j - i] + i);
        }
    }
    return dp[n] == n ? true : false;
}

int main() {
    unordered_map<int, int> uMap;
    uMap[1] = 1;
    uMap[2] = 2;
    uMap[3] = 3;
    std::for_each (
        uMap.begin(), 
        uMap.end(), 
        [](std::pair<int, int> p) {
            if (!is_Valid(p.second)) {
                return -1;
            }
        }
    );
    return 0;
}