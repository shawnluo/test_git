
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>

double binaryFractionToDecimal(const string& binaryFraction) {
    size_t dotPosition = binaryFraction.find('.');
    string integerPart;
    string fractionalPart;
    if(dotPosition == string::npos) {   // 找到 "." 号
        integerPart = binaryFraction;
        fractionalPart = "";
    } else {
        integerPart = binaryFraction.substr(0, dotPosition);		// substr(起始位，长度)
        fractionalPart = binaryFraction.substr(dotPosition + 1);	// substr(起始位)： 从起始位到string的结束
    }

    double decimalInteger = 0.0;
    for(int i = 0; i < integerPart.size(); i++) {
        if(integerPart[i] == '1') {
            decimalInteger += pow(2.0, integerPart.size() - i - 1);
			/* or 
			    resInt <<= 1;
        		resInt += (intPart[i] - '0');
			*/
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



















// C++ program to convert a decimal 
// number to binary number 

#include <iostream> 
using namespace std; 

// function to convert decimal to binary 
void decToBinary(int n) { 
	// array to store binary number 
	int binaryNum[32]; 

	// counter for binary array 
	int i = 0; 
	while (n > 0) { 

		// storing remainder in binary array 
		binaryNum[i] = n % 2; 
		n = n / 2; 
		i++; 
	} 

	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--) 
		cout << binaryNum[j]; 
} 

// C++ program to convert binary to decimal 
// when input is represented as binary string. 
// Function to convert binary to decimal 
int binaryToDecimal(string n) { 
	string num = n; 
	int dec_value = 0; 

	// Initializing base value to 1, i.e 2^0 
	int base = 1; 

	int len = num.length(); 
	for (int i = len - 1; i >= 0; i--) { 
		if (num[i] == '1') 
			dec_value += base; 
		base = base * 2; 
	} 

	return dec_value; 
} 


// Driver program to test above function 
int main() { 
	int n = 17; 
	decToBinary(n); 

	string num = "10101001"; 
	cout << binaryToDecimal(num) << endl; 

	return 0; 
} 
