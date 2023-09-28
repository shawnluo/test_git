
#include "test.hpp"

void test_revers_iterator(vector<int> nums) {
    vector<int>::reverse_iterator rit;
    for(rit = nums.rbegin(); rit != nums.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
}


int main(void) {
    const vector<int> nums = {1, 2, 3, 4, 5};
    test_revers_iterator(nums);

    return 0;
}