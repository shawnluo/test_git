
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>


double binaryFractionToDecimal(const string& binaryFraction) {
    size_t dotPosition = binaryFraction.find('.');
    string integerPart = binaryFraction.substr(0, dotPosition);
    string fractionalPart = binaryFraction.substr(dotPosition + 1);

    double decimalInteger = 0.0;
    for(int i = 0; i < integerPart.size(); i++) {
        if(integerPart[i] = '1') {
            decimalInteger += pow(2.0, integerPart.size() - i - 1);
        }
    }

    double decimalFraction = 0.0;
    for(int i = 0; i < fractionalPart.size(); i++) {
        if(fractionalPart[i] == '1') {
            decimalFraction += pow(2.0, -(i + 1));
        }
    }

    return decimalInteger + decimalFraction;
}

int main() {
    std::string binaryFraction = "110.01101";
    double decimalFraction = binaryFractionToDecimal(binaryFraction);

    std::cout << "Binary Fraction: " << binaryFraction << std::endl;
    std::cout << "Decimal Fraction: " << decimalFraction << std::endl;

    return 0;
}