#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

/* strtol example */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* strtol */

int test(vector<int> nums) { return *std::max_element(nums.begin(), nums.end()); }

int main(void) {
    vector<int> nums{ 2, 3, -2, 4 };
    cout << test(nums) << endl;

    return 0;
}