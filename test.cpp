#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;



class myClass {
public:
	myClass() {
		cout << "Constructor invoked" << endl;
	}
	~myClass() {
		cout << "Desstructor invoked" << endl;
	}
};

int main(void) {
    weak_ptr<int>wePtr;
    {
    shared_ptr<int>shPtr = make_shared<int>(25);
    wePtr = shPtr;
    // cout << wePtr.expired() << endl;
    // cout << *wePtr << endl;
    // cout << shPtr.use_count() << endl;
    // cout << wePtr.use_count() << endl;
    // // cout << *wePtr << endl;
    // wePtr.reset();
    // cout << wePtr.use_count() << endl;
    // cout << shPtr.use_count() << endl;

    // wePtr.expired();
    // cout << wePtr.use_count() << endl;
    // cout << shPtr.use_count() << endl;

    shared_ptr<int> sh_ptr = wePtr.lock();
    cout << *sh_ptr << endl;
    *sh_ptr = 100;
    cout << *shPtr << endl;
    }
    // cout << wePtr.expired() << endl;

    return 0;
}