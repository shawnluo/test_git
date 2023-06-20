#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
using namespace std;

// 1.1
int test(const char *s) {
	int hash[256] = {0};
	for(int i = 0; i < strlen(s); i++) {
		if(hash[s[i]]) {return 0;}
		else {hash[s[i]] = 1;}
	}
	return 1;
}

// 1.2
void reverse_s(char *s) {
	char *pL = s;
	char *pR = s + strlen(s) - 1;

	while(pL != pR) {
		char tmp = *pL;
		*pL = *pR;
		*pR = tmp;
		pL++, pR--;
	}
	cout << s << endl;
}

// 1.3
void remove_dup(char *s) {
	if(!s) return;

	char *pL = s;
	char *pR = pL + 1;
	char *tmp = s;
	while(*pR != '\0') {
		for(tmp = s; tmp <= pL; tmp++) {
			
		}
	}
}

int main(void) {
	// char *s = "abcd";
	// auto res = test(s);
	// cout << res << endl;

	char s[] = "abc";
	reverse_s(s);
	return 0;
}