#include "test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <unistd.h>

/* strtol example */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* strtol */


int myRead(const char* f, const int size) {
	FILE* fp;
	char buf[size];
	memset(buf, 0, size);
	int res = 0;

	fp = fopen(f, "r");
	if(fp == nullptr) {
		perror("Error opening file");
		return -1;
	}

	char* s;
	while((s = fgets(buf, size, fp)) != nullptr) {
		// cout << s << " : ";
		// cout << buf << endl;
		// cout << strlen(buf) << endl;
		// cout << strlen(s) << endl;
		res += strlen(buf);
	}
	return res;
}

FILE* fp;
char buf[size];
memset(buf, 0, size);
fp = open(f, "r");
if(!fp)	{
	perror("Error opening file");
	return -1;
}

while(fgets(buf, size, fp) != nullptr) {
	res += strlen(buf);
}
return res;

int main(void) {
	cout << myRead("test.tmp", 5) << endl;

    return 0;
}