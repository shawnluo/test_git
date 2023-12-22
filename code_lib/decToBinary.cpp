
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>

double binaryFractionToDecimal(const string& s) {
    size_t pos = s.find('.');
    string intPart;
    string fractionalPart;
    if(pos == string::npos) {   // 找到 "." 号
        intPart = s;
        fractionalPart = "";
    } else {
        intPart = s.substr(0, pos);		// substr(起始位，长度)
        fractionalPart = s.substr(pos + 1);	// substr(起始位)： 从起始位到string的结束
    }

	// 注意数据类型！！！！！！！！！！！！
    double resInt = 0.0;
    for(int i = 0; i < intPart.size(); i++) {
        if(intPart[i] == '1') {
            resInt += pow(2.0, intPart.size() - i - 1);
			/* or 
			    resInt <<= 1;
        		resInt += (intPart[i] - '0');
			*/
        }
    }

    double resFraction = 0.0;
    for(int i = 0; i < fractionalPart.size(); i++) {
        if(fractionalPart[i] == '1') {
            resFraction += pow(2.0, -(i + 1));
        }
    }

    return resInt + resFraction;
}


string int2Bin(int n) {
    // 12 -> 1100
    string res;
    for(int i = n; i > 0; ) {
        res.insert(0, to_string(i % 2));
        i /= 2;
    }

    double x = 0.6875;  // 0.1011    用push_back
    if(x > 0) {
        res.push_back('.');
    }
    for(; x; ) {
        x = x * 2;
        res.push_back((int)x + '0');	// 类型转换成整型
        
        x = x >= 1 ? x - 1 : x;
    }
    cout << res << endl;

    return res;
}


int main() {
    std::string s = "110.01101";
    double resFraction = binaryFractionToDecimal(s);

    std::cout << "Binary Fraction: " << s << std::endl;
    std::cout << "Decimal Fraction: " << resFraction << std::endl;

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
