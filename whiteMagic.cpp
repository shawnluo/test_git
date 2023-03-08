#include "iostream"
using namespace std;

/*  [100]
    virtual function
*/
class animal {
public:
	virtual int eat()   {return 10;}
};

class plant {
public:
	int eat()           {return 25;}
};

//多态第一步，要有继承
class mouse: public animal {
public:
    //多态第二步，要有函数重写（重写发生在2个类之间，两个类之间有继承关系，且出现同名的函数；虚函数重写将发生多态）
	virtual int eat()   {return 20;}
};

class bird: public animal {
public:
	virtual int eat()   {return 30;}
};

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
		cout << name_pub << endl;	//2. OK!
		cout << name_pro << endl;	//2. OK! - protected data can ONLY be accessed in the class
		cout << name_pri << endl;	//1. OK! - private data can ONLY be accessed in the class
		
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
		cout << name_pri << endl;	//4. Failed! - private data can NOT be accessed by derived class
	}
};

int test(void) {
	animal monster;
	cout << monster.name_pub << endl;	//5. OK!
	cout << monster.name_pro << endl;	//6. Failed! - proteced data can NOT be accessed by outside.
	cout << monster.name_pri() << endl;	//7. Failed! - private data can NOT be accessed by outside of the class which difined the data.

	return 0;
}
