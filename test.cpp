


#include "test.hpp"
#include <thread>

using namespace std;

string intToRoman(int num) {
    // 1. divide by M, untile mode == 1
    // 2. divide by D, untile mod == 1
    // ...

    string res;
    vector<pair<string, int>> v = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, \
                                    {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};

    for(int i = 12; i >= 0; i--) {
        for(; num >= v[i].second; ) {
            cout << "i = " << i << "\t" << num << endl;
            res.append(v[i].first);
            num -= v[i].second;
        }
    }

    // cout << res << endl;
    return res;
}

public int romanToInt(String s) {
    int res=0;
    for(int i=0;i<s.length();i++){
        char c = s.charAt(i);
        if(c=='I'){
            if(i+1<s.length()&&s.charAt(i+1)=='V'){
                res+=4;
                i++;
            }else if(i+1<s.length()&&s.charAt(i+1)=='X'){
                res+=9;
                i++;
            }else res+=1;
        }else if(c=='X'){
            if(i+1<s.length()&&s.charAt(i+1)=='L'){
                res+=40;
                i++;
            }else if(i+1<s.length()&&s.charAt(i+1)=='C'){
                res+=90;
                i++;
            }else res+=10;
        }else if(c=='C'){
            if(i+1<s.length()&&s.charAt(i+1)=='D'){
                res+=400;
                i++;
            }else if(i+1<s.length()&&s.charAt(i+1)=='M'){
                res+=900;
                i++;
            }else res+=100;
        }else if(c=='V') res+=5;
        else if(c=='L') res+=50;
        else if(c=='D') res+=500;
        else if(c=='M') res+=1000;
    }
    return res;
}

int romanToInt(string s) {

}

int main(void) {
    cout << intToRoman(1994) << endl;

    return 0;
}