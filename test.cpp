#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
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
    test* t1 = new test_I2C();
    test* t2 = new test_SPI();

    test::callAPI(t1);
    test::callAPI(t2);

    test_I2C p1;
    test_SPI p2;

    test::callAPI(p1);
    test::callAPI(p2);

    return 0;
}