
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


// char* simplifyPath(char* path, char* res) {
//     vector<char> stack;
//     int size = 0;
//     for(char* token = strtok(s, needle); token; token = strtok(nullptr, needle)) {
//         cout << token << endl;
//         if(strcmp(token), ".") ;
//         else if(strcmp(token, "..") == 0) {
//             size = max(0, size - 1);
//         } else {
//             stack[size++] = token;
//         }
//     }
//     if(size == 0) {
//         return "/";
//     }

//     for(int i = 0; i < size; i++) {
//         strcat(res, "/");
//         strcat(res, stack[i]);
//     }

//     return res;
// }

// char* myStrtok(char* hay, const char needle) {
//     static char* input = nullptr;
//     if(hay != nullptr) {
//         input = hay;
//     }
//     if(input == nullptr) {
//         return nullptr;
//     }

//     char* res = (char*)malloc(sizeof(char) * 20);
//     int i = 0;
//     for( ; input[i] != '\0'; i++) {
//         if(input[i] != needle) {
//             res[i] = input[i];
//         } else {
//             res[i] = '\0';
//             input = input + i + 1;
//             return res;
//         }
//     }
//     res[i] = '\0';
//     input = nullptr;

//     return res;
// }

// find 2 nums, sum equals to target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        auto x = map.find(target - nums[i]);
        if(x != map.end()) 
            return {i, x->first};

        map[i] = nums[i];
    }
    return {};
}

for(auto a : A) {
    for(auto b : B) {
        map[a + b]++;
    }
}

for(auto c : C) {
    for(auto d : D) {
        if(map.find(0 - c - d) != map.end())
            res += map[0 - c - d];
    }
}
return res;

for(int i = 3; i < size; i++) {
    for(int j = 1; j < i; j++) {
        dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
    }
}

for(int i = 0; i < size; i++) {
    for(int j = BAG; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}

for(int i = 0; i < size; i++) {
    for(int j = 0; j <= BAG; j++) {
        if(dp[j - coins[i]] != INT_MAX) {
            dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        }
    }
}

if(dp[BAG] == INT_MAX) {
    return -1;
}
return dp[BAG];

int main(){
    // test_strtok();
    // int nums[5] = {1, 3, 5, 2, 4};

    // int res = partition(nums, 0, 4);
    // sort(nums, 0, 4);

    // for(int i = 0; i < 5; i++) {
    //     cout << nums[i] << endl;
    // }

    return 0;
}