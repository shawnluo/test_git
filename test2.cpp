#include "test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>


#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;



int main(void) {
    queue<char> q;
    q.push('a');
    q.push('b');

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    return 0;
}