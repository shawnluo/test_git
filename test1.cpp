
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


char* simplifyPath(char* path, char* res) {
    vector<char> stack;
    int size = 0;
    for(char* token = strtok(s, needle); token; token = strtok(nullptr, needle)) {
        cout << token << endl;
        if(strcmp(token), ".") ;
        else if(strcmp(token, "..") == 0) {
            size = max(0, size - 1);
        } else {
            stack[size++] = token;
        }
    }
    if(size == 0) {
        return "/";
    }

    for(int i = 0; i < size; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }

    return res;
}

for(char* token = strtok(s, needle); token; token = strtok(nullptr, needle)) {

}


char* myStrtok(char* hay, const char needle) {
    static char* input = nullptr;
    if(hay != nullptr) {
        input = hay;
    }
    if(input == nullptr) {
        return nullptr;
    }

    char* res = (char*)malloc(sizeof(char) * 20);
    int i = 0;
    for( ; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];
        } else {
            res[i] = '\0';
            input = input + i + 1;
            return res;
        }
    }
    res[i] = '\0';
    input = nullptr;

    return res;
}

int main(){
    test_strtok();
    // int nums[5] = {1, 3, 5, 2, 4};

    // int res = partition(nums, 0, 4);
    // sort(nums, 0, 4);

    // for(int i = 0; i < 5; i++) {
    //     cout << nums[i] << endl;
    // }

    return 0;
}