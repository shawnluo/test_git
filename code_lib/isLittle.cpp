

int isLittle(void) {
    int  i  = 1;
    char *c = (char *)&i;

    return *c == 1 ? true : false;
}