#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

void test(vector<int>& v) {
    int j = 0;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] != v[i - 1]) {
            v[++j] = v[i];
        }
    }
    v.resize(++j);
}

void showMe(const vector<int>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

int main(void) {
    vector<int> v{1, 2, 2, 2, 3, 3, 4};
    test(v);

    showMe(v);

    return 0;
}