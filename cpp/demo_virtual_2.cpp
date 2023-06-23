#include <iostream>
using namespace std;

class base {
public:
	base() {
		// cout << "base construction " << endl;
	}

	// void disp() {
	virtual void disp() {	//using virtual 
		cout << "Hello, base" << endl;
	}
};

class child1 : public base {
public:
	child1() {
		// cout << "child1 construction " << endl;
	}
	void disp() { // 派生类child1中定义的disp()函数将base类中定义的disp()函数隐藏
		cout << "hello, child1" << endl;
	}
};

class child2 : public base {
public:
	void disp() {
		cout << "hello, child2" << endl;
	}
};

// 注意这里，指针使用的是基类指针base作为参数！
// 因为调用的是虚函数，那么根据传入的派生类对象参数，会指向派生类对象的disp()函数。
// 如果disp() 不是虚函数，那么会指向base中的disp()函数.
// 实现一种接口，多种方法
void display(base *pb) {
	pb->disp();
}

int main(void) {
	base *pBase = NULL, obj_base;
	obj_base.disp();
	pBase = &obj_base;
	pBase->disp();
	
	child1 *pchild1 = NULL, obj_child1;
	obj_child1.disp();
	pchild1 = &obj_child1;
	pchild1->disp();

	child2 *pchild2 = NULL, obj_child2;
	obj_child2.disp();
	pchild2 = &obj_child2;
	pchild2->disp();
	
	pBase = &obj_child1;
	pBase->disp();

	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);

	return 0;
}