
#include "test.hpp"


bool test(void) {
    int n = 11;
    int res = 0;
    while(n) {
        n &= (n - 1);
        res++;
    }
    return res == 1 ? true : false;
}

int read(char* buf, int n) {
    char buf4[4];
    int readChars = 4;
    int copiedChars = 0;

    while(readChars == 4 && copiedChars < n) {
        readChars = read4(buf4);

        for(int i = 0; i < readChars; i++) {
            if(copiedChars == n) return copiedChars;
            buf[copiedChars] = buf4[i];
            copiedChars++;
        }
    }
    return copiedChars;
}

int main(void) {
    // test();
    test();

    return 0;
}