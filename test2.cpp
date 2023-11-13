#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>



int test(unordered_map<int, int> map) {
    int size = map.size();
    int res = 0;
    for(auto key : map) {
        // if(map.find())
        // cout << key.first << endl;
        auto it = map.find(key.first + 1);
        if(it != map.end()) {
            res = max(res, key.second + it->second);
            // cout << it->second << endl;
        }
    }
    return res;
}

int main(void) {
	unordered_map<int, int> map;
    map.insert(pair<int, int>(2, 5));
    map.insert(pair<int, int>(3, 8));
    // map.insert(pair<int, int>(4, 5));
    map.insert(pair<int, int>(5, 5));
    map.insert(pair<int, int>(6, 1));
    map.insert(pair<int, int>(7, 8));
    // map[3] = 6;
    // map[5] = 3;
    
	// cout << map[2] << endl;

    cout << test(map) << endl;

    std::cout << "Binary Fraction: " << binaryFraction << std::endl;
    std::cout << "Decimal Fraction: " << decimalFraction << std::endl;

    return 0;
}