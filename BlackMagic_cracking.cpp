#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
using namespace std;

#if 0
// 1.1
int test(const char *s) {
	int hash[256] = {0};
	for(int i = 0; i < strlen(s); i++) {
		if(hash[s[i]]) {return 0;}
		else {hash[s[i]] = 1;}
	}
	return 1;
}
#endif

#if 0
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
#endif

#if 0
// 1.3
void remove_dup(char *s) {
	if(!s) return;

	char *pL = s;
	char *pR = s + 1;
	char *tmp = NULL;
	while(*pR != '\0') {
		for(tmp = s; tmp <= pL; tmp++) {
			if(*tmp == *pR) {break;}
		}
		if(tmp > pL) {
			*(++pL) = *(pR);
		}
		pR++;
	}
	*(pL + 1) = '\0';

	cout << s << endl;
}
#endif

#if 0
// 1.4
int is_anagram(const char *s1, const char *s2) {
	if(!s1 || !s2) {
		cout << "invalid input!\n";
		return -1;
	}
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 != len2) {return 0;}

	int hash[256] = {0};
	for(int i = 0; i < len1; i++) {
		hash[s1[i]]++;
	}
	for(int i = 0; i < len2; i++) {
		hash[s2[i]]--;
	}
	for(int i = 0; i < 256; i++) {
		if(hash[i] != 0) {return 0;}
	}
	return 1;
}
#endif

#if 0
//1.5
void replace_spaces(char *s) {
	int count = 0;
	int len = strlen(s);
	int len_new;

	int i, j;
	for(i = 0; i < len; i++) {
		if(s[i] == ' ') {count++;}
	}
	len_new = count * 2 + strlen(s);


	for(i = len_new - 1, j = len - 1; i >= 0; ) {
		if(s[j] == ' ') {
			s[i] = '0';
			s[i - 1] = '2';
			s[i - 2] = '%';
			j--;
			i -= 3;
		} else {
			s[i] = s[j];
			i--, j--;
		}
	}
	cout << s << endl;
}
#endif

#if 0
// 1.6.1
void rotate_matrix(void) {
	int mat[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}};

	int new_mat[4][3] = {0};

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			new_mat[j][3 - 1 - i] = mat[i][j];
		}
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			cout << new_mat[i][j];
		}
		cout << endl;
	}
}
#endif

#if 0
// 1.6.2
void rotate_mat_inplace() {
	int mat[4][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
		{12, 13, 14, 15}};

	int n = 4;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	for(int i = 0; i < n / 2; i++) {
		for(int j = 0; j < n / 2; j++) {
			int tmp = mat[i][j];
			mat[i][j] = mat[j][n - i - 1];
			mat[j][n - i - 1] = mat[n - i - 1][n - j - 1];
			mat[n - i - 1][n - j - 1] = mat[n - j - 1][i];
			mat[n - j - 1][i] = tmp;
		}
	}

	cout << "---------------------------" << endl;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
#endif

#if 0
// 3.4
void move(char x, char y) {
	cout << x << " -> " << y << endl;
}

//				   from    buf      to
void hanoi(int n, char a, char b, char c) {
	if(n == 1) {
		move(a, c);
	} else {
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}
#endif

#if 0
// 3.5 MyQueue which implements a queue using two stacks
void imp_que_using_
#endif

#if 0
// leetcode 88. Merge Sorted Array
/*
	Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
	Output: [1,2,2,3,5,6]
	Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
	The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	if(m == 0 && n == 0) {
		return;
	}
	int res[m + n];
	int left = 0, right = 0;
	int count = 0;
	while(count < m + n) {
		if(left >= m) {
			res[count++] = nums2[right++];
		} else if(right >= n) {
			res[count++] = nums1[left++];
		} else if(nums1[left] >= nums2[right]) {
			res[count++] = nums2[right++];
		} else {
			res[count++] = nums2[left++];
		}
	}

	for(int i = 0; i < m + n; i++) {
		nums1[i] = res[i];
	}
}
#endif

#if 1

#endif

int main(void) {
	// char *s = "abcd";
	// auto res = test(s);
	// cout << res << endl;

	// char s[20] = "abca x";
	// reverse_s(s);
	// remove_dup(s);
	// replace_spaces(s);
	// rotate_matrix();
	// rotate_mat_inplace();
	hanoi(5, 'a', 'b', 'c');

	return 0;
}