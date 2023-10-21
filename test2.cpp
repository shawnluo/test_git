#include "test.hpp"

#include <iostream>
#include <cstdlib>



int main() {
	// int x = 5;
	int left = (1 << 4) - 1;
	int right = (1 << 2) - 1;

	printf("0x%x\n", left);
	printf("0x%x\n", right);
	printf("0x%x\n", left - right);

	return 0;
}