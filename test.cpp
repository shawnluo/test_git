


#include "test.hpp"
#include <thread>

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

void task2() {
    for(int i = 0; i < 5; i++) {
        sleep(1);
        // this_thread::sleep_for(chrono::seconds(1));
        cout << "task2 - " << i << endl;
    }
}

int main(void) {
    auto f = [](int x) {
        for(int i = 0; i < x; i++) {
            cout << "Thread using lambda"
                    " expression as callable\n";
        }
    };

    auto z = []() {
        cout << "gogogo\n";
    };

    thread th3(z);
    // thread th3(f, 3);
    th3.join();

    // vector<int> arr = {10, 1, 7, 2, 3, 4, 5, 9, 6, 8, 0};

    // background_task f;
    // thread th1(background_task(), 100);
    // thread th2(task2);
    // th2.detach();

    // cout << "main before exit!" << endl;

    // sleep(3);

    // cout << "main exit!" << endl;
    // if(pthread_cancel(th1.native_handle()) != 0) {
    //     cerr << "Failed to cancel thread" << endl;
    //     return 1;
    // }

    // th1.join();

    return 0;
}