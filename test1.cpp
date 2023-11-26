
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


#include <iostream>
#include <string>

int main() {
    std::thread my_thread([] {
        while (1) {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "in thread" << endl;
        }
    });
    this_thread::sleep_for(chrono::seconds(2));
    my_thread.detach();
    cout << "after detach" << endl;

    for(;;) {sleep(1);} 
    pthread_exit(nullptr);
    cout << " main exit! " << endl;

    return 0;
}