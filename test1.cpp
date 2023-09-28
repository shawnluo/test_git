
#include "test.hpp"

void test() {
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;

    vector<vector<int>> val;
    vector<int> val_;
    val_.push_back(a);
    val_.push_back(b);
    val.push_back(val_);
    val_.clear();

    val_.push_back(c);
    val_.push_back(d);
    val.push_back(val_);

    for(auto x : val) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    
}

void test_revers_iterator(vector<int> nums) {
    vector<int>::reverse_iterator rit;
    for(rit = nums.rbegin(); rit != nums.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
}


int main(void) {
    // const vector<int> nums = {1, 2, 3, 4, 5};
    // test_revers_iterator(nums);

    test();

    return 0;
}