
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// int isSub(string s1, string s2) {
int isSub(char *s1, char *s2) {
/* 
    loop s1
        if s[i] == s2 reaches to the end, 
            then yes

    return false
*/
    // char *p1, *p2;
    for( ; *(s1 + strlen(s2) - 1) != '\0'; s1++) {
        if(strncmp(s1, s2, strlen(s2)) == 0) {
            return 1;
        }
        // printf("%d\n", strlen(s2));
    }
    return 0;
}

int main(void) {
    // vector<int> nums{1, 1, 2, 2, 2, 3, 4, 5, 5};
    // vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // cout << lengthOfLCS(nums) << endl;
    // cout << dp_46(nums) << endl;

    char s1[] = "abcde";
    char s2[] = "fab";

    int ret = strncmp(s1, s2, 5);
    // printf("%d\n", strlen(s2));

    printf("%d\n", isSub(s1, s2));

    return 0;
}