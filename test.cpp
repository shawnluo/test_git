#include "test.hpp"

typedef void (*fun)(void);


void fun1() {
    for(int i = 0; i < 10; i++) {
        cout << " - fun1 - " << " ";
    }
    cout << endl;
}

void fun2() {
    for(int i = 0; i < 10; i++) {
        cout << " - fun2 - " << " ";
    }
    cout << endl;
}

void threadTask(fun f, int sec) {
    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(sec * 1000));
        f();
    }
}

void runTask(fun f) {
    std::thread t1(threadTask, f, 1);
    t1.detach();
    // cout << " - t1 detached - " << endl;
    // t1.join();
}



int main(void) {
    runTask(fun1);
    runTask(fun2);

    while(1) {
        sleep(1);
    }

    return 0;
}