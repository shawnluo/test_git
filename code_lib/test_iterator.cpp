#include "test.hpp"
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)


void test_const_iterator(vector<int> nums) {    
    vector<int>::const_iterator it; // it can NOT be changed
    for(it = nums.begin(); it != nums.end(); it++) {
        // *it = 4;    // wrong!
        cout << *it << " ";
    }
    cout << endl;
}

void test_iterator(vector<int> nums) {
    vector<int>::iterator it; // it can be changed
    for(it = nums.begin(); it != nums.end(); it++) {
        *it = 4;    // ok!
        cout << *it << " ";
    }
    cout << endl;
}

void test_revers_iterator(vector<int> nums) {
    vector<int>::reverse_iterator rit;
    for(rit = nums.rbegin(); rit != nums.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
}


int main(void) {
    const vector<int> nums = {1, 2, 3, 4, 5};

    test_iterator(nums);
    test_const_iterator(nums);
    test_revers_iterator(nums);

    return 0;
}