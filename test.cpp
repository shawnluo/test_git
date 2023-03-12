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
int partition(int *sums, int start, int end) {
	int save = sums[end];
	int left = start - 1;
	int right;
	for(right = start; right < end; right++) {
		if(sums[right] > save) {
			left++;
			swap(sums[left], sums[right]);
		}
	}
	swap(sums[left + 1], sums[end]);
	
	return left + 1;
}

//TODO 2	signals


int main(void) {
	//animal monster;
	//cout << monster.name_pro << endl;	//5. Failed! - proteced data can NOT be accessed by outside.
	//cout << monster.name_pub << endl;	//6. Failed! - private data can NOT be accessed by outside of the class which difined the data.
    
	int nums[] = {2, 7, 5, 4};
	int res = partition(nums, 0, 3);
	cout << "pivot: " << res << endl;
	for(int i = 0; i < 4; i++) {
		cout << nums[i] << endl;
	}

	return 0;
}
