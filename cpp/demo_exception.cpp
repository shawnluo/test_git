#include <iostream>
#include <exception>
#include <memory>
// using namespace std;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_unique;
using std::make_shared;
using std::move;


struct MyException : public std::exception {
    const char* what() const throw() {
        return "C++ Exception";
    }
};

double division_1(int a, int b) {
    if(b == 0) {
        throw "Diveion by zero condition --------";
    }
    return (a / b);
}

double division_2(int a, int b) {
    if(b == 0) {
        throw MyException();
    }
    return (a / b);
}

void simple_e() {
    int x = 50;
    int y = 0;
    double z = 0;
    
    try {
        z = division_1(x, y);
        cout << z << endl;
    } catch(const char* msg) {
        cerr << msg << endl;
    }
}

void adv_e() {
    int x = 50;
    int y = 0;
    double z = 0;
    
    try {
        z = division_2(x, y);
        cout << z << endl;
    } catch(MyException& e) {
        cout << "MyException caught" << endl;
        cout << e.what() << endl;
    } catch(std::exception& e) {

    }

}


int main(void) {
    simple_e();
    adv_e();

    return 0;
}