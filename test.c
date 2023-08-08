
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

char *myStrtok(char *hay, const char needle) {
    static char *input = NULL;
    if(hay != NULL) {
        input = hay;
    }
    if(input == NULL) {
        return NULL;
    }
    char *res = (char*)malloc(sizeof(char) * 20);
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


void delDup(pNode pHead) {
    if(pHead == NULL) return;

    pNode pPre = pHead;
    pNode pCur = pHead->next;
    pNode runner;
    while(pCur) {
        runner = pHead;
        while(runner != pCur) {
            if(runner->data == pCur->datra) {
                pPre->next = pCur->next;
                break;
            }
            runner = runner->next;
        }
        if(runner == pCur) {
            pPre = pCur;
            pCur = pCur->next;
        }
        
    }
}


int main(void) {
    test();
    return 0;
}