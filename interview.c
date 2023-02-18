/*
    1. a1b2c3a8c6 -> a9b2c9
*/
void print_hash(int hash[], int size) {
    for(int i = 0; i < 256; i++) {
        printf("%d, ", hash[i]);
    }
}

void convert_string(void) {
    char *s = "a1b2c3a8c6";
    //1. using hash table to store the number of character
    //2. go throught hash[256] to store char with number

    int hash[256] = {0};
    int size = strlen(s);
    int sum = 0;
    int save = 0;
    int i, j;
    for(i = 0; i < size; ) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            save = i;
            i++;
            sum = 0;
            while(s[i] >= '0' && s[i] <= '9') {
                sum += sum * 10 + s[i] - '0';
                i++;
            }
            hash[s[save]] += sum;
        }
    }
    
    //print_hash(hash, 256);

    char res[1000] = {0};
    char c_tmp[1000] = {0};
    for(i = 0; i < 256; i++) {
        if(hash[i]) {
            sprintf(c_tmp, "%c", i);
            printf("%s\n", c_tmp);
            strcat(res, c_tmp);
            sprintf(c_tmp, "%d", hash[i]);
            printf("%s\n", c_tmp);
            strcat(res, c_tmp);
        }
    }

    printf("%s\n", res);
}