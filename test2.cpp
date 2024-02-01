#include "test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>


#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;




class test {
public:
    int val;

    test() {}
    test(int data) : val(data) {}

    virtual void api() {
        cout << "test SPI" << endl;
    }
    void set(int val);
    void show() const ;

    test operator+(const test& other) {
        return test(val + other.val);
    }

private:
    friend void showMe(test);
    friend class peek;
};

/* class peek {
public:
    peek(test x) {
        cout << x.val << endl;
    }
};

void showMe(test x) {
    cout << x.val << endl;
}

void test::set(int val) {
    cout << this->val << endl;
    cout << val << endl;
}

void test::show() const {
    cout << "show" << endl;
}

class test_I2C : public test {
public:
    virtual void api() {
        cout << "tet I2C" << endl;
    }
}; */

int main(void) {
    test x(33);
    test y(55);
    test z = x + y;

    cout << z.val << endl;

    return 0;
}