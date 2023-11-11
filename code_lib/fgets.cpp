#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

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

    /* char *fgets(char *s, int size, FILE *stream);
        每次读取size - 1大小的字节数据，然后加上'\0'来结尾！！！  比如： size = 5,    读取 1234 + '\0'
        直到遇到文件结尾符号，返回NULL
    */
	char* s;
	while((s = fgets(buf, size, fp)) != nullptr) {
		cout << s << " : ";
		cout << buf << endl;
		cout << strlen(buf) << endl;
		cout << strlen(s) << endl;
		res += strlen(buf);
	}
	return res;
}

int main(void) {
	std::cout << myRead("test.tmp", 5) << std::endl;

    return 0;
}


/*
test.tmp:
1234567890

输出：
1234
5678
90
*/