#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
#include "test.hpp"
#include "complex.hpp"

using namespace std;


class Base {
public:
	// Base(int n) : key(n) {
	// 	cout << "in Base: action" << key << endl;
	// }

	virtual void showMe(){
		cout << "in Base: showMe" << endl;
	}

	void action(int n) {
		cout << "in Base: action" << endl;
	}
	void listen();

	static int number;
	int key;
};

class Mars : public Base {
public:
	Mars(int n) : key(n) {
		cout << "in Base: action" << key << endl;
	}

	void showMe() {
		cout << "in Mars: showMe" << endl;
	}

	int key;
};

void showme(Base *pb) {
	pb->showMe();
}

void Base::listen(){
	cout << "in Base: listen" << endl;
}

int Base::number = 100;

int main(void) {
	Base base();
	// base.showMe();
	base.listen();

	Mars mars(200);
	// mars.showMe();

	showme(&base);
	showme(&mars);



	return 0;
}