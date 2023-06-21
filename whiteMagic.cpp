#include "iostream"
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
using namespace std;

/************************************************************************************************
	[001]
    virtual function
*/
class animal {
public:
	virtual int eat()   {return 10;}
};

class plant {
public:
	int eat()           {return 25;}	//1. virtual function. You can redefine it. But it's not have to do.
};

class mouse: public animal {
public:
	virtual int eat()   {return 20;}
};

class bird: public animal {
public:
	virtual int eat()   {return 30;}
};


//pure virtual function
class god {
	virtual int run() = 0;	//2. pure virtual function. 2.1. so god class cannot be instantation
}

god mygod;	//2.2. failed.

class mygod: god {
public:
	virtual int run() {
		cout << "run" << endl;	//2.3 MUST be redefined in derived class
	}
}

//多态的第三步，用父类指针(父类引用)指向子类对象....//即在函数的形参使用父类的对象替代子类对象，但是在调用重写了的虚函数时，仍然调用的是传递过来子类对象的函数
void playLand(animal &animal, plant *plant) {
	if (animal.eat() > plant -> eat())  cout << "动物赢了" << endl;
	else                                cout << "植物赢了" << endl;
}

int main(void) {
	animal animal1;
	mouse mouse1;
	bird bird1;
	plant flowers;

	playLand(animal1, &flowers);
	playLand(mouse1, &flowers);
	playLand(bird1, &flowers);

    return 0;
}

/************************************************************************************************
	[001] - 2
    virtual function - 一种接口，多个方法
*/


/************************************************************************************************
	[002]
*/


class car {
private:
	string name = "name_pri";
protected:
	string date = "name_pro";
public:
	car() {
		cout << name_pub << endl;	//1. OK!
		cout << name_pro << endl;	//2. OK! - protected data can ONLY be accessed in the class
		cout << name_pri << endl;	//3. OK! - private data can ONLY be accessed in the class
	}
	string number = "name_pub";
};

class tesla: public car {
public:
	string name;
	tesla() {
		cout << name_pro << endl;	//4. OK! - protected data can be accessed by derived class
		cout << name_pri << endl;	//5. Failed! - private data can NOT be accessed by derived class
	}
};

class ford: private car {
private:
	string name;
};

class nissan: protected car {
protected:
	string date;
};


int test(void) {
	car monster;
	cout << monster.name_pub << endl;	//6. OK!
	cout << monster.name_pro << endl;	//7. Failed! - proteced data can NOT be accessed by outside.
	cout << monster.name_pri() << endl;	//8. Failed! - private data can NOT be accessed by outside of the class which difined the data.

	tesla ev;
	cout << ev.name_pub << endl;	//9. OK!

	ford focus;
	cout << focus.name_pub << endl;	//10. Failed!

	nissan leaf;
	cout << leaf.name_pub << endl;	//11. Failed!

	return 0;
}


/************************************************************************************************
 * 	[003]
 * 	overload (重载): 同一个类中。函数名相同，参数个数，顺序，类型或返回值不同
 * 	override (重写): 不在同类中。指派生类重新定义基类的虚函数。有virtual关键字，不能有static
 *  Overwrite is meaning Override without virtual keyword.
 * 	redefine (): 不在同类中。函数名相同，参数个数，顺序，类型或返回值可以不同
 */
class Base {
public:
    virtual void a(int x)    {    cout << "Base::a(int)" << endl;      }
    // overload the Base::a(int) function
    virtual void a(double x) {    cout << "Base::a(double)" << endl;   }
    virtual void b(int x)    {    cout << "Base::b(int)" << endl;      }
    void c(int x)            {    cout << "Base::c(int)" << endl;      }
};

class Derived : public Base {
public:
    // redefine the Base::a() function
    void a(complex<double> x)   {    cout << "Derived::a(complex)" << endl;      }
    // override the Base::b(int) function
    void b(int x)               {    cout << "Derived::b(int)" << endl;          }
    // redefine the Base::c() function
    void c(int x)               {    cout << "Derived::c(int)" << endl;          }
};

int main() {
    Base b;
    Derived d;
    Base* pb = new Derived;
    // ----------------------------------- //
    b.a(1.0);                              // Base::a(double)
    d.a(1.0);                              // Derived::a(complex)
    pb->a(1.0);                            // Base::a(double), This is redefine the Base::a() function
    // pb->a(complex<double>(1.0, 2.0));   // clear the annotation and have a try
    // ----------------------------------- //
    b.b(10);                               // Base::b(int)
    d.b(10);                               // Derived::b(int)
    pb->b(10);                             // Derived::b(int), This is the virtual function
    // ----------------------------------- //
    delete pb;

    return 0;
} 

/*	[004] vector
*/
int test_vector(void) {
	//0.
	vector<int> vec;
	for(int i = 0; i < 10; i++)		vec.push_back(i);

	vector<int> nums1 = {1, 2, 3, 4, 5};
	for(int x : nums1)	cout << x << endl;

	int size = 5;
	vector<int> nums(size, 0);

	vector<int>::iterator itr;
	for(itr = nums.begin(); itr != nums.end(); itr++)	cout << *itr << endl;

	//1. 
	for(unsigned int i = 0; i < vec.size(); i++) 	cout << vec[i] << endl;

	//2. 
	vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) 	cout << *it << endl;

	//3.
	vec.insert(vec.begin() + 4, 0);
	for(unsigned int i = 0; i < vec.size(); i++) 	cout << vec[i] << endl;

	//4.
	vec.erase(vec.begin() + 2);
	for(unsigned int i = 0; i < vec.size(); i++) 	cout << vec[i] << endl;

	//5.
	vec.erase(vec.begin() + 3, vec.begin() + 5);
	for(vector<int>:: iterator it = vec.begin(); it != vec.end(); it++) cout << *it << endl;

	return 0;
}

template<class T>
void printVector(std::vector<std::vector<T>> const &matrix) {
    for (std::vector<T> row: matrix) {
        for (T val: row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void vector_init() {
	//one dimension vector initlization: way1
	int size = 5;
	vector<int> nums_1(size);

	//one dimension vector initlization: way2
	vector<int> nums_2;
	nums_2.resize(size);

	//two dimension: way1
	int size_row = 5;
	int size_col = 3;
	vector<vector<int>> nums_3(size_row, vector<int> (size_col, 0));

	//two dimension: way2
	vector<vector<int>> nums_4;
	nums_4.resize(size_row);
	for(int i = 0; i < size_col; i++)	nums_4[i].resize(size_col);

	printVector(nums_4);
}

/******************************************************************************************
	[005] template
*/
template <class T>	/*1. 声明类模板时必须写的关键字
							mimtype并不是一个已存在的实际类型名，
							它只是一个虚拟类型参数名。在以后将被一个实际的类型名取代。*/
class Compare {
public:
	Compare(T a, T b) {
		x = a;
		y = b;
	}
	T max()	{return x > y ? x : y;}
	T min()	{return x < y ? x : y;}

private:
	T x, y;
};

int test_template(void) {
	Compare <int> cmp1(4, 7);	/*2. 必须用实际类型名去取代虚拟的类型, 把类模板实例化 */
	cout << cmp1.max() << endl;
	cout << cmp1.min() << endl;

	Compare <float> cmp2(23.5, 98.97);
	cout << cmp2.max() << endl;
	cout << cmp2.min() << endl;

	return 0;
}

/******************************************************************************************
	[006] reference
*/
//2. how to initlize
int &ref; //wrong code! reference must be initilized to a obj. - like a link

int x{100}
int &ref{x}		// way1
int &ref = x	// way2

//3. understand "reference will point to the initlized obj forever!"
	int x = 100;
	int y = 200;

	int &ref = x;
	cout << ref << endl;	// 100

	ref = y;
	cout << x << endl;		// 200 - ref still points to x, it just changed the value to y

	y = 300;
	cout << ref << endl;	// still 200 ! - ref will points to x forever!


/******************************************************************************************
	[007] const
	知识点1：
		getvalue2() const ；
	知识点2：
		使用const Func mars来实例化
*/
class Func {
public:
    int value;
    Func();
    virtual ~Func();
    const int getValue();		// 前面加了const，表示返回值为const
    int getValue2 () const ;	// 使用const, 此函数内部不能修改成员函数value
								// 成员函数可以被非const对象和const对象调用
};


Func::Func() : value (1200) {

}

Func::~Func() {

}

const int Func::getValue() {
	value = 5;
	return value;
}

int Func::getValue2() const {	// 使用const, 此函数不能修改成员函数value
	// value = 15;				// wrong! 因为函数后面加了const, 此函数不能修改value
	return value;
}

int main() {
	Func mars;
	int res = mars.getValue();	// OK
	res = mars.getValue2();		// OK

	const Func mars2;		// 使用const, 
	res = mars.getValue();	// wrong! 实例化使用了const, 则需要调用const类型的方法getvalue2()
	res = mars.getValue2();	// OK!

	return 0;
}


/******************************************************************************************
	[008] operator
	知识点1：
		getvalue2() const ；
	知识点2：
		使用const Func mars来实例化
*/
class Box {
public:
	double getVolume(void) {
		return length * breadth * height;
	}
	void setLength(double len) {
		length = len;
	}
	void setBreadth(double bre) {
		breadth = bre;
	}
	void setHeight(double hei) {
		height = hei;
	}

	Box operator+(const Box& b) {
		Box box;
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}

private:
	double length;
	double breadth;
	double height;
};


int main() {
	Box Box1;
	Box Box2;
	Box Box3;
	double volume = 0.0;

	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);

	volume = Box1.getVolume();
	cout << "Volume of Box1 : " << volume << endl;

	volume = Box2.getVolume();
	cout << "Volume of Box2 : " << volume << endl;

	Box3 = Box1 + Box2;

	volume = Box3.getVolume();
	cout << "Volume of Box3 : " << volume << endl;

	return 0;
}

/******************************************************************************************
	[011] friend
*/
class CB {
public:
	CB() {
		cout << "CB::construction\n";
	}
	virtual void f(int) {
		cout << "CB::f(int)" << endl;
	}
	
	// virtual void f1() = 0;

	void f2() {
		cout << "CB::f2" << endl;
	}

private:
	int var = 19;

	friend void Dog(CB);
	friend class Cat;
};

void Dog(CB x) {
	cout << x.var << endl;
}

class Cat {
public:
	void cat(CB x) {
		cout << x.var << endl;
	}
};

int main(void) {
	CB tt;
	Dog(tt);
	Cat x;
	x.cat(tt);

	return 0;
}

/******************************************************************************************
	[013] string
*/
	//1. string to char *
	string s = "gooday!";
	const char *a = s.c_str();	//must use const
	const char *b = s.data();	//must use const
	cout << a << endl;
	cout << b << endl;

	//2. char * to string
	char *a = "good";
	string s = a;


/******************************************************************************************
	[014] class instance
*/
	// 1. on stack
	base Base_stack(6);
	Base_stack.disp();

	// 2. on heap
	base *Base_heap = new base(7);
	Base_heap->disp();
	delete Base_heap;

	// 3. on heap
	base *Base_heap2 = NULL, obj_heap2(100);
	obj_heap2.disp();
	delete Base_heap2;