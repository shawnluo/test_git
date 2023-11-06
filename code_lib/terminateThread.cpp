
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>

#include <sys/prctl.h> 
using namespace std;


class Foo {
public:
    void sleep_for(const std::string& tname, int num) {
        prctl(PR_SET_NAME, tname.c_str(), 0, 0, 0); // 给线程设置名字
        sleep(num);
    }

    void start_thread(const std::string& tname) {
        std::thread thrd = std::thread(&Foo::sleep_for, this, tname, 3600);
        tm_[tname]       = thrd.native_handle();
        thrd.detach();
        std::cout << "Thread " << tname << " created:" << std::endl;
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
};


int main() {
    Foo foo;
    std::string keyword("test_thread");
    std::string tname1 = keyword + "1";
    std::string tname2 = keyword + "2";


    // create and kill thread 1
    foo.start_thread(tname1);
    foo.stop_thread(tname1);


    // create and kill thread 2
    foo.start_thread(tname2);
    foo.stop_thread(tname2);


    return 0;
}