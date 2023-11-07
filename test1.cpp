
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


void test_strtok() {
    char s[] = "show me the money";
    char* needle = " ";

    for(char* token = strtok(s, needle); token; token = strtok(nullptr, needle)) {
        cout << token << endl;
    }
}

char* myStrtok(char* hay, const char needle) {
    static char* input = nullptr;
    if(hay != nullptr) {
        input = hay;
    }
    
    if(input == nullptr) return nullptr;

    char* res = (char*)malloc(sizeof(char) * 20);
    int i = 0;
    for( ; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];
        } 
    }
}

int main() {
    test_strtok();

    return 0;
}