
#include "test.hpp"

#include <semaphore.h>
#include <unistd.h>
using namespace std;


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;


class CEmployee {
private:
    int age;
    int id;

public:
    CEmployee() { cout << "这是构造函数" << endl; }

    CEmployee(int id) { this->id = id; }
    
    ~CEmployee() { cout << "这是析构函数" << endl; }
    
    void OutputName() { cout << this->id << endl; }
};

int main() {
    CEmployee cEmployee1;    // 隐式创建并调用无参构造器
    CEmployee cEmployee2(2); // 隐式创建并调用有参构造器
    return 0;
}