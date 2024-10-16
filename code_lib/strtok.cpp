char *my_strtok(char *hay, const char needle) {
    static char *input = NULL;
    if(hay != NULL) input = hay;
    if(input == NULL) return NULL;

    char *res = (char *)calloc(20, sizeof(char));
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];
        } else {
            res[i] = '\0';
            input = input + i + 1;
            return res;
        }
    }
    res[i] = '\0';
    input = NULL;

    return res;
}