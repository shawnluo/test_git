#include "test.hpp"



string intToBin(int num) {
    if(num == 0) return "0";

    string res;
    while(num > 0) {
        char mod = (num % 2) + '0';
        res = mod + res;
        num /= 2;
    }
    return res;
}

string decToBin(float num) {
    string res;
    
    while(num > 0) {
        if(res.size() > 32) {
            // return "ERROR";
            return res;
        }
        num *= 2;
        if(num >= 1) {
            res = res + "1";
            num -= 1.0;
        } else {
            res = res + "0";
        }
    }
    
    return res;
}

int main(void){
    float n = 8.14;
    string res_int = intToBin(n);

    float decimal = n - (int)n;
    string res_dec = decToBin(decimal);

    cout << res_int + "." + res_dec << endl;

    return 0;
}