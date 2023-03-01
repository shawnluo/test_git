#include "common.h"
#include "test.h"

char *my_strtok(const char *hay, const char needle) {
    static char *s = NULL;
    char *res = (char *)calloc(sizeof(char) * strlen(hay));
    while(*hay) {
        if(*hay == needle) {
            //set s and return res
            strncpy(res, hay, s - hay + 1);
            s = hay + 1;
            return res;
        }
        hay++;
    }
    return res;
}

int main(void) {
    const char hay[] = "abc def c!";
    char needle = ' ';
    my_strtok(hay, needle);

    return 0;
}