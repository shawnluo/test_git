#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

#include <iostream>
#include <string>


#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

typedef struct Person {
    string name;
    int age;
} PERSON;

int main() {
    PERSON a = {"Alice", 10};
    PERSON b = {"Bob", 20};
    PERSON c = {"Charlie", 35};

    vector<PERSON> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    for(auto it : v) {
        cout << it.name << endl;
    }

    string targetName = "Charlie";

    auto it = std::find_if(v.begin(), v.end(), [&](const Person& p) {
        // cout << p.name << endl;
        return p.name == targetName;
    });

    if(it != v.end()) {
        cout << "Person: " << targetName << "found. Age: " << it->age << endl;
    } else {
        cout << "Person: " << targetName << " not found." << endl;
    }

    return 0;
}