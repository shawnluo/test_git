#include "iostream"
using namespace std;

/*  [001]
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


/*	[003]
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
