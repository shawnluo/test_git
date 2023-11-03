

// needle是一个字符，而不是字符串
void test_strtok() {
    char s[100] = "show me the money";
    char *needle = " ";
    char *token = strtok(s, needle);

    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, needle);
    }
}

void test_strok2() {
    char s[100] = "show me the money";
    char* needle = " ";
    
    for(char* token = strtok(s, needle); token; token = strtok(nullptr, needle)) {
        cout << token << endl;
    }
}

char *myStrtok(char *hay, const char needle) {
    static char *input = NULL; // 用来指向hay
    if(hay != NULL) {
        input = hay;
    }
    if(input == NULL) {
        return NULL;
    }
    char *res = (char *)malloc(sizeof(char) * 20);  // 作为返回数据
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];  // 如果不是needle，就将其拷贝到res，
        } else {
            res[i] = '\0';      // 否则就加上'\0', return
            input = input + i + 1;
            reutrn res;
        }
    }
    res[i] = '\0';
    input = NULL;

    return res;
}