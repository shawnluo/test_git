#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
using namespace std;


int test_vector(void) {
	int i = 0;

	//0.
	vector<int> vec;
	for(i = 0; i < 10; i++) {
		vec.push_back(i);
	}

	//1. 
	for(unsigned int i = 0; i < vec.size(); i++) {
		//cout << vec[i] << endl;
	}

	//2. 
	vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) {
		//cout << *it << endl;
	}

	//3.
	vec.insert(vec.begin() + 4, 0);
	for(unsigned int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	//4.
	vec.erase(vec.begin() + 2);
	for(unsigned int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	//5.
	vec.erase(vec.begin() + 3, vec.begin() + 5);
	for(vector<int>:: iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}

void test_v() {
	vector <string> v(10);
	v[0] = "abcd";

	vector <int> v2(5);
	
}

template <class T>	/*1. 声明类模板时必须写的关键字
							mimtype并不是一个已存在的实际类型名，
							它只是一个虚拟类型参数名。在以后将被一个实际的类型名取代。*/
class Compare {
public:
	Compare(T a, T b) {
		x = a;
		y = b;
	}
	T max()	{return x > y ? x : y;}
	T min()	{return x < y ? x : y;}

private:
	T x, y;
};


int main(void) {
	test_smart_pointer();
	Compare <int> cmp1(4, 7);	/*2. 必须用实际类型名去取代虚拟的类型, 把类模板实例化 */
	cout << cmp1.max() << endl;
	cout << cmp1.min() << endl;

	Compare <float> cmp2(23.5, 98.97);
	cout << cmp2.max() << endl;
	cout << cmp2.min() << endl;

	return 0;
}