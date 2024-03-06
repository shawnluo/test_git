#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

#include <iostream>
#include <string>


#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

#include <iostream>
#include <queue>


// 4 2
/* 
12 13 14 
23 24
34
*/
vector<vector<int>> res;
vector<int> path;
void test(int n, int k, int pos) {
    if((int)path.size() == k) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i <= n; i++) {
        path.push_back(i);
        test(n, k, i + 1);
        path.pop_back();
    }
}

// swap
void test2() {

}

// used
void test3(vector<int>& nums, vector<bool>& used) {
    if(path.size() == nums.size()) {
        res.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(used[i] == true) continue;
        used[i] = true;
        path.push_back(nums[i]);
        test3(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

int main() {
    res.clear();
    path.clear();
    vector<int> v{1, 2, 3};
    vector<bool> used(v.size(), false);

    test3(v, used);

    for(auto it : res) {
        for(auto y : it) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}