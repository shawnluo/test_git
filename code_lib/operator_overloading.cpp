#include "../test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;



// 1. simple operator overloading example
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


// 2. C++ Operator Overloading Example

#include <iostream>

class Complex {
public:
    double real;
    double imaginary;

    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    // Overloading the + operator for Complex numbers
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloading the - operator for Complex numbers
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Overloading the * operator for Complex numbers
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    // Overloading the / operator for Complex numbers
    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator,
                       (imaginary * other.real - real * other.imaginary) / denominator);
    }

    // Overloading the << operator for Complex numbers (for printing)
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imaginary << "i)";
        return os;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(5, -2);

    // Using the overloaded operators
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;

    // Printing the results
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c3 = c1 + c2 = " << c3 << std::endl;
    std::cout << "c4 = c1 - c2 = " << c4 << std::endl;
    std::cout << "c5 = c1 * c2 = " << c5 << std::endl;
    std::cout << "c6 = c1 / c2 = " << c6 << std::endl;

    return 0;
}