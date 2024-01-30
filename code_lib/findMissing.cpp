
#include "test.hpp"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;


int findMissing(vector<int>& array, int column) {
    if (column < 0) return 0;

    vector<int> odd;
    vector<int> eve;
    // odd.clear();
    // eve.clear();

    for (auto it : array) {
        if ((it >> column) & 1) {
            odd.push_back(it);
        } else {
            eve.push_back(it);
        }
    }

    if(odd.size() >= eve.size()) {
        return (findMissing(eve, column - 1)) << 1 | 0;
    } else {
        return (findMissing(odd, column - 1)) << 1 | 1;
    }
}

int findMissing(vector<int>& array) {
    return findMissing(array, array.size() - 1);
}

int main(void) {
    vector<int> array = {1, 2, 3, 5, 6, 7};
    cout << findMissing(array) << endl;

    return 0;
}