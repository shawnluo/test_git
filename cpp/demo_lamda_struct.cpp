#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
    capture by reference: capture x and modify the original x
*/
void test1(void) {
    int x = 10;
    auto fun = [&]() -> int {
        x = 23;
        return x;
    };

    cout << fun() << endl;  // 23
    cout << x << endl;      // 23
}

/* 
    capture by value: capture x, and using mutable to modify the copy
*/
void test2(void) {
    int x = 10;
    auto fun = [x]() mutable -> int {
        x = 23;
        return x;
    };

    cout << fun() << endl;  // 23
    cout << x << endl;      // 10
}


int main() {
    struct {
        void operator() (int x) {
            std::cout << x << "\n";
        }
    } something;

    struct Person {
        std::string name;
        int age;
        char gender;

        void print() {
            std::cout << age << " - ";
            std::cout << name << " - ";
            std::cout << gender << std::endl;
        }
    };

    int d = 3, e = 5;

    std::vector<int> v{2, 3, 7, 14, 23};

    std::for_each(v.begin(), v.end(), [&d, e](int x){  // if d has been changed, then use reference.
    // std::for_each(v.begin(), v.end(), [&](int x){  // if all the parameters have been changed, then use single reference.
    // std::for_each(v.begin(), v.end(), [=](int x){  // if all the parameters have NOT been changed, then use single equal.
        if(x % d == 0)
            std::cout << x << " is divisible by " << d << "\n";
        else
            std::cout << x << " is not divisible by " << d << "\n";
        d = 10;
    });
    std::for_each(v.begin(), v.end(), something);

    Person p1 = {"Bob", 15, 'M'};
    Person p2 = {"Janet", 17, 'F'};

    p1.print();
    p2.print();

    return 0;
}