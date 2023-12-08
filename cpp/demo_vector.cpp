#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
#include "test.hpp"
#include "complex.hpp"

using namespace std;
using std::cout;
using std::endl;
using std::string;


vector <int> v[5];
void insertionInArrayOfVectors() {
	for(auto i = 0; i < 5; i++) {
		for(auto j = i + 1; j < 5; j++) {
			v[i].push_back(j);
		}
	}
}


void printElements() {
	for(auto i = 0; i < 5; i++) {
		cout << "Elements at index " << i << ": ";

		for(auto it = v[i].begin(); it != v[i].end(); it++) {
			cout << *it << ' ';
		}
		cout <<endl;
	}
}


void arrayOfVectors() {
	insertionInArrayOfVectors();
	printElements();
}


int main(void) {
	// char *s = nullptr;
	// arrayOfVectors();

	// vector <string> vec;
	// vec.push_back("hello ");
	// vec.push_back("cpp !");
	// for(vector <string>::iterator i = vec.begin(); i != vec.end(); i++) {
	// 	cout << *i;
	// }
	// cout << endl;

	string s = "12345";
	cout << *(s.begin()) << endl;
	cout << *(s.end()) << endl;
	cout << s.size() << endl;

	return 0;
}


// ----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

typedef struct Person {
    string name;
    int age;
} PERSON;

/* 
	In this example, we have a vector  people  of  Person  structs, with each struct having a  
	name  and  age  field. We want to search for the person with the name  "Bob" . We use  
	std::find_if  to search for the first element that satisfies the given condition, 
	which we define using a lambda function. The lambda function compares the  name  field 
	of each  Person  struct with the target name. If a match is found,  std::find_if  returns 
	an iterator pointing to that element. We can then access the  age  field of the found element 
	using  it->age . 
 */

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