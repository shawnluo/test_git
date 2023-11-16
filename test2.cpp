#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>



class MyClass {
public:
    int* data;
    int size;

    MyClass(int size) : size(size) {
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = i;
        }
        cout << "cons" << endl;
    }

    ~MyClass() {
        delete[] data;
        data = nullptr;
        cout << "des" << endl;
    }
};

class Book {
public:
    string Title;
    string Author;
    float* Rates;
    int RatesCounter;

    Book(string title, string author) : Title(title), Author(author) {
        // Title = title;
        // Author = author;

        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 5;
        Rates[1] = 4;
    }

    void getAttr() {
        cout << this->Title << endl;
    }

    ~Book() {
        cout << "destruction" << endl;
        delete[] Rates;
        Rates = nullptr;
    }

};

template<typename T>
class complex {
public:
    complex(T r = 0, T i = 0) : re(r), im(i) {}
    // complex() : re(0), im(0) {}  // WRONG! compiler will get confused!

    complex& operator += (const complex&);
    inline T real() const {return re;}  // 必须要使用const，因为创建实例的时候，可能使用了const，这里如果不加const的话，会出错！！！
    inline T imag() const {return im;}

private:
    T re, im;

    // friend complex& __doapl(complex*, const complex&);
};


int main() {
    complex c1(2, 1);
    cout << c1.real() << " ";
    cout << c1.imag() << endl;

    complex<int>* p1 = new complex(5, 6);
    cout << p1->real() << " ";
    cout << p1->imag() << endl;

    complex<float>* p2 = new complex(1.1f, 2.3f);   // 这里要注意！float占4个字节。数据后要加上f
    cout << p2->real() << " ";
    cout << p2->imag() << endl;

    const complex<double>* p3 = new complex(1.1, 2.3);   // 这里要注意！double占8个字节。
    cout << p3->real() << " ";
    cout << p3->imag() << endl;

    // MyClass obj1(5);
    // MyClass obj2 = obj1;

    // Book book1("shawn's book", "shawn");
    // book1.getAttr();

    // Book book2(book1);

    return 0;
}