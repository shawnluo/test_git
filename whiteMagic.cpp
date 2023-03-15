#include "iostream"
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
using namespace std;

/************************************************  
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


/************************************************
	[002]
*/

class animal {
public:
	animal() {
		cout << name_pub << endl;	//1. OK!
		cout << name_pro << endl;	//2. OK! - protected data can ONLY be accessed in the class
		cout << name_pri << endl;	//3. OK! - private data can ONLY be accessed in the class
		
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
		cout << name_pro << endl;	//4. OK! - protected data can be accessed by derived class
		cout << name_pri << endl;	//5. Failed! - private data can NOT be accessed by derived class
	}
};

int test(void) {
	animal monster;
	cout << monster.name_pub << endl;	//6. OK!
	cout << monster.name_pro << endl;	//7. Failed! - proteced data can NOT be accessed by outside.
	cout << monster.name_pri() << endl;	//8. Failed! - private data can NOT be accessed by outside of the class which difined the data.

	return 0;
}


/************************************************
 * 	[003]
 * 	overload: 同一个类中。函数名相同，参数个数，顺序，类型或返回值不同
 * 	override: 不在同类中。指派生类重新定义基类的虚函数。有virtual关键字，不能有static
 * 	redefine: 不在同类中。函数名相同，参数个数，顺序，类型或返回值可以不同
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