

/* cracking the coding 5.2
    Given a (decimal - e g   3 72) number that is passed in as a string, print the binary rep-resentation   
    If the number can not be represented accurately in binary, print “ERROR”
*/

#include <iostream>
#include <bitset>

using namespace std;


#include "test.hpp"

string printBin_IntPart(int n) {
    string s;
    while(n) {
        int r = n % 2;
        n >>= 1;
        s = std::to_string(r) + s;
    }

    return s;
}

string printBin_DecPart(double n) {
    string s;
    while(n) {
        if(s.size() > 32)
            return "ErRROR";

        if(n == 1) {
            s = s + std::to_string(n);
            break;
        }
        
        if(n * 2 >= 1) {
            s = s + std::to_string(1);
            n = n * 2 - 1;
        } else {
            s = s + std::to_string(0);
            n = n * 2;
        }
    }
    return s;
}

int main(void) {
    string s = printBin_IntPart(8);
    cout << s << endl;

    return 0;
}

// 方法一：
// bitset<32>(x): 将x转化为32位二进制数

int main() {
	int x = 38^40;
	
	cout << bitset<sizeof(x)*8>(x) << endl; //int占4字节，一个字节8位，最终输出的是32个0或1
	cout << bitset<8>(x) << endl;//输出8位 
	return 0;
}


// 方法二：
void bin_print(int n) {
    unsigned char *p = (unsigned char *)&n;
    p = p + 3;

    for(int j = 0; j < 4; j++) {
        for(int i = 7; i >= 0; i--) {
            if((*p) & (1 << i)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        p--;
        printf("\n");
    }
}