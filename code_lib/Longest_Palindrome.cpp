
#include "test.hpp"


/*
    409. Longest Palindrome
*/

int longestPalindrome(string s) {
    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }
    int even = 0;
    int odd = 0;

    for(int i = 0; i < 256; i++) {
        even += hash[i] / 2 * 2;
        odd += hash[i] % 2;
    }
    odd = odd > 0 ? 1 : 0;
    return even + odd;
}

int main(void) {
    string s = "aaaaa";
    cout << longestPalindrome(s) << endl;

    return 0;
}