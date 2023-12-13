#include "test.hpp"

#include <semaphore.h>
#include <functional>
#include <thread>
using namespace std;


int main(void) {
    vector<int> v(5, -2);
    for(auto it : v) {
        cout << it << endl;
    }
    return 0;
}