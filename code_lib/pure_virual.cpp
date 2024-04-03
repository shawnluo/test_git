
#include "../test.hpp"

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
    virtual void api() = 0;

    virtual void api2() {}

    static void callAPI(test& api) {
        api.api();
        api.api2();
    }

    static void callAPI(test* api) {
        api->api();
        api->api2();
    }
};

class test_I2C : public test {
public:
    virtual void api() {
        cout << " - test I2C " << endl;
    }

    void api2() {
        cout << " - test I2C - virtual function " << endl;
    }
};

class test_SPI : public test {
public:
    virtual void api() {
        cout << " - test SPI " << endl;
    }

    void api2() {
        cout << " - test SPI - virtual function " << endl;
    }
};


int main(void) {
    // 1. call children class directly
    test_I2C t1;
    test_SPI t2;

    t1.api();

    test::callAPI(t1);
    test::callAPI(t2);

    // 2. call base class
    test* tt1 = new test_I2C(); // pure virtual function cannot instantiate, but can point to children class
    test* tt2 = new test_SPI();

    test::callAPI(tt1);
    test::callAPI(tt2);

    return 0;
}