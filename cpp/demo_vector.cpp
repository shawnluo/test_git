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


/* 1. push_back 
 */
void test() {
    vector<vector<int>> res;
    res.push_back(vector<int>{v[i], v[j], v[k]});   // 可以尾部接 vector
    res.push_back('a');             // push_back只能尾部接单个字符(char), 而不是字符串(char*)
}

/* 2. insert
 */
int n = 1;
res.insert(0, to_string(n));    // insert只能插入字符串(char*)，而不是字符(char)
                                // to_string(int n), 将数字转换成字符串


/* 3. replace
 */
string s = "0123456";
// 从s的第三个字符开始，接下来两个"34"，用"abcd"来替换！
cout << s.replace(3, 2, "abcd") << endl;

string s = "012";
cout << s.replace(3, 2, "abcd") << endl;    // 012abcd

string s = "01";
cout << s.replace(3, 2, "abcd") << endl;    // will fail


/* 4. max/min
 */
auto it_max = std::max_element(v.begin(), v.end());
auto it_min = std::min_element(v.begin(), v.end());
cout << *it_max << endl;
cout << *it_min << endl;


// ------------------- front ------------------------------

// first element
cout << v.front() << endl;

// ------------------- back ------------------------------
// last element
cout << v.back() << endl;

// ------------------- at ------------------------------
/* access the first element */
cout << v.at(0);

/* access the last element */
cout << v.at(v.size() - 1);

// ------------------- find ------------------------------
bool findInVec(int n) {
    vector<int> v = {1, 2, 3};
    if(std::find(v.begin(), v.end(), 3) != v.end()) {
        // cout << 1 << endl;
        return true;
    }
    return false;
}

// ------------- push_back ----------------------

vector <int> v[5];
void insertionInArrayOfVectors() {
	for(auto i = 0; i < 5; i++) {
		for(auto j = i + 1; j < 5; j++) {
			v[i].push_back(j);
		}
	}
}


// iterate vector
void printElements() {
	for(auto i = 0; i < 5; i++) {
		cout << "Elements at index " << i << ": ";

		for(auto it = v[i].begin(); it != v[i].end(); it++) {
			cout << *it << ' ';
		}
		cout <<endl;
	}
}

// ----------------------- vector<pair<string, int>> v -----------------------------------------
    vector<pair<string, int>> v;
    v.push_back({"show", tid0});
    v.push_back({"show", tid1});
    auto it = std::find_if(v.begin(), v.end(), [&](const pair<string, int>& p) {
        return p.second == 3;
    });

    if(it != v.end()) {
        cout << "find it" << endl;
    } else {
        cout << "cannot find it" << endl;
    }
// ----------------------- vector<struct node> v -----------------------------------------

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