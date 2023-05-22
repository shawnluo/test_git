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

class car {
private:
	string name;
protected:
	string date;
public:
	unsigned int number;
};

class tesla: public car {
public:
	string name;
};

class ford: private car {
private:
	string name;
};

class nissan: protected car {
protected:
	string date;
};


// Driver Code
int main()
{
	car trans;

	return 0;
}
