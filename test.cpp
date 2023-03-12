#include <iostream>
#include <string.h>
#include "common.h"
using namespace std;

class animal {
public:
	animal() {
		cout << name_pri << endl;	//1. OK! - private data can ONLY be accessed in the class
		cout << name_pro << endl;	//2. OK! - protected data can ONLY be accessed in the class
	}
	string name_pub = "name_pub";

protected:
	string name_pro = "name_pro";

private:
	string name_pri = "name_pri";
};

class dog: animal {
public:
	dog() {
		cout << name_pro << endl;	//3. OK! - protected data can be accessed by derived class
		//cout << name_pri << endl;	//4. Failed! - private data can NOT be accessed by derived class
	}
};


//TODO 1
void partition(int *sums, int left, int right) {
	int save = sums[right];
	while() {

	}
}

//TODO 2	signals


int main(void) {
	//animal monster;
	//cout << monster.name_pro << endl;	//5. Failed! - proteced data can NOT be accessed by outside.
	//cout << monster.name_pub << endl;	//6. Failed! - private data can NOT be accessed by outside of the class which difined the data.
    
	int x = 9;
	char c = '9';
	cout << c << endl;
	return 0;
}
