
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
#include <sys/prctl.h> 
using namespace std;


typedef void (*pF)();

void fun1() {
    cout << " - fun1 - " << endl;
}

void fun2() {
    cout << " - fun2 - " << endl;
}

class Foo {
public:
    void start_thread(const std::string& tname, pF f, int hz) {
        /*
        The  `this`  pointer is used to refer to the current object. In this case, the  `this`  pointer is used to pass the  `runAPI`  object to the  `caller`  function. This allows the  `caller`  function to access the  `tName`  and  `f`  members of the  `runAPI`  object.*/
        std::thread thrd = std::thread(&Foo::caller, this, tname, f, hz);   // 注意这里需要用 this 来显性地表示调用的是本class的函数
        tm_[tname]       = thrd.native_handle();
        thrd.detach();
        std::cout << "Thread " << tname << " created!" << std::endl;
    }

    void stop_thread(const std::string& tname) {
        ThreadMap::const_iterator it = tm_.find(tname);
        if (it != tm_.end()) {
            pthread_cancel(it->second);
            tm_.erase(tname);
            std::cout << "Thread " << tname << " killed!" << std::endl;
        }
    }

private:
    typedef std::unordered_map<std::string, pthread_t> ThreadMap;
    ThreadMap tm_;

    void caller(const std::string& tname, pF f, int hz) {
        // prctl(PR_SET_NAME, tname.c_str(), 0, 0, 0); // 给线程设置名字，不要可以
        while(1) {
            f();
            sleep(hz);
            // cout << " caller " << endl;
        }
    }
};

int main() {
    Foo foo;
    std::string keyword("test_thread");
    std::string tname1 = keyword + "1";
    std::string tname2 = keyword + "2";

    foo.start_thread(tname1, fun1, 1);
    
    sleep(1);

    foo.start_thread(tname2, fun2, 2);

    sleep(2);

    foo.stop_thread(tname1);

    sleep(2);

    foo.stop_thread(tname2);

    cout << " ------ over ------ " << endl;

    while(1) {
        sleep(1);
        cout << " - in main - " << endl;
    }

    return 0;
}


// TODO

using namespace std;

class background_task {
public:
    void operator()(int val) const {
        while(1) {
            cout << "111 - " << val << endl;
            sleep(1);
            // pthread_testcancel();
        }
    }

    static void foo(int i) {
        cout << "foo" << endl;
    }
};

class taskManager {
    void startThread() {

    }

    void stopThread() {

    }
};

int main(void) {
    vector<int> arr = {10, 1, 7, 2, 3, 4, 5, 9, 6, 8, 0};

    // background_task f;
    thread th1(background_task(), 100);
    sleep(3);
    if(pthread_cancel(th1.native_handle()) != 0) {
        cerr << "Failed to cancel thread" << endl;
        return 1;
    }

    th1.join();

    return 0;
}