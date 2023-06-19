// C++ program to demonstrate the function
// strtok() to tokenized the string
#include <bits/stdc++.h>
using namespace std;

/*
Here is my code for the design of a parking lot in C++. The following assumptions are made. Referred from Geeks for Geeks

The parking lot has multiple levels. Each level has multiple rows of spots.
The parking lot can park motorcycles, cars, and buses.
The parking lot has motorcycle spots, compact spots, and large spots.
A motorcycle can park in any spot.
A car can park in either a single compact spot or a single large spot.
A bus can park in five large spots that are consecutive and within the same row. It cannot park in small spots
*/


class A {
	int num;
public:
	int set_num() 		{this->num = 100;};
	int get_num() const {return num;}
};

void test(const A& a) {
	auto res = a.get_num();
	cout << res << endl;
}

// Driver Code
int main() {
	A a;
	a.set_num();
	test(a);
	
	return 0;
}
