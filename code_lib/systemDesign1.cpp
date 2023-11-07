
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
#include <sys/prctl.h> 
using namespace std;


typedef void (*fP)();

void fun1() {
    cout << " - fun1 - " << endl;
}

void fun2() {
    cout << " - fun2 - " << endl;
}

class Foo {
public:
    void start_thread(const std::string& tname, fP f, int hz) {
        std::thread thrd = std::thread(&Foo::caller, this, tname, f, hz);
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

    void caller(const std::string& tname, fP f, int hz) {
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