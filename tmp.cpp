
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


#include <iostream>
#include <string>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class test {
public:
    test();
    ~test();

    void fun();
    virtual int api() = 0;
};

test::test() {
    cout << " - init" << endl;
}

test::~test() {
    cout << " - uninit" << endl;
}

class test_I2c: public test {
public:
    virtual int api() {
        cout << "test I2c" << endl;
        return 1;
    }
};

class test_SPI: public test {
public:
    virtual int api() {
        cout << "test SPI" << endl;
        return 2;
    }
};

void callAPI(test &api) {
    api.api();
}

class mycom {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

int main() {
    test_I2c t1;
    test_SPI t2;

    callAPI(t1);
    callAPI(t2);

    return 0;
}