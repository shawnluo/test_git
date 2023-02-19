#include "common.h"
#include "test.h"

bool validWordAbbreviation(char * word, char * abbr){
    char *pos1 = word;
    char *pos2 = abbr;
    //int size = strlen(word);

    int num = 0;
    while(*pos2) {
        num = 0;
        while(*pos2 >= '0' && *pos2 <= '9') {
            num = num * 10 + *pos2 - '0';
            pos2++;
        }
        //printf("%d\n", num);
        pos1 += num;
        if(*pos1 != '\0' && *pos2 != '\0' && *pos1 != *pos2) {
            return false;
        }
        pos1++, pos2++;
    }
    return true;
}
int main(void) {
    // break_int(8);
    int res = validWordAbbreviation("internationalization", "i12iz4n");
    printf("%d\n", res);

    return 0;
}