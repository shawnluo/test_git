#include <iostream>
using namespace std;

class Super {
public:
    virtual string getName1(int x) {
        return "Super";
    }

    virtual string getName2(int x) const {
        return "Super";
    }
};

class Sub: public Super {
public:
    // virtual string getName1(double x) override {
    virtual string getName1(int x) override {
        return "Sub";
    }

    virtual string getName2(int x) const override {
        return "Sub";
    }

    virtual string getName3(int x) {
        return "Sub";
    }
};

class Sub_1: public Sub {
public:
    virtual string getName2(int x) const override{
        return "sub_1";
    }

    virtual string getName3(int x) override {
        return "Sub";
    }
};

int main() {
    Sub sub;
    Super* super = &sub;

    cout << super->getName1(1) << endl;  // output: Super
    cout << super->getName2(2) << endl;  // output: Super

    // cin.ignore(10);
    return 0;
}