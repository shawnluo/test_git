#include "test.hpp"

#include <iostream>
#include <cstdlib>


int read(char *buf, int n) {
    int readChars = 4;
    int copiedChars = 0;
    int buf4[4];

    while(copiedChars < n && readChars == 4) {
        readChars = read4(buf4);

        for(int i = 0; i < readChars; i++) {
            if(copiedChars == n) {
                return copiecChars;
            }
            buf[copiedChars] = buf4[i];
            copiedChars++;
        }
    }
    return copiedChars;
}