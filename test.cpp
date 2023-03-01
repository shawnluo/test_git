#include <iostream>
#include <string.h>
#include "common.h"
using namespace std;

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


char *my_strtok(char *hay, const char needle) {
    static char *s = NULL;
    char *res = new char[strlen(hay) + 1];
    while(*hay) {
        if(*hay == needle) {
            //set s and return res
            strncpy(res, hay, s - hay + 1);
            s = hay + 1;
            return res;
        }
        hay++;
    }
    return res;
}


int main(void) {
	animal animal1;
	mouse mouse1;
	bird bird1;
	plant flowers;

	//playLand(animal1, &flowers);
	//playLand(mouse1, &flowers);
	//playLand(bird1, &flowers);

    char hay[] = "abc def c!";
    char needle = ' ';
    my_strtok(hay, needle);


    return 0;
}
