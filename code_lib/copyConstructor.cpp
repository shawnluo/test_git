
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>


/* 
浅拷贝（shallowCopy）：
对于基本数据类型和简单对象，他们之间的拷贝非常简单，就是按位复制内存，这种默认的拷贝行为就是浅拷贝，这和memcpy()函数的调用效果类似。

深拷贝（deepCopy）：
深拷贝会将原有对象的所有成员变量拷贝给新对象，对于指针等数据还会为新对象重新在堆上分配一块内存，并将原有对象所持有的堆上的数据也拷贝过来，这样能保证原有对象和新对象所持有的动态内存都是相互独立的，更改一个对象的数据不会影响另一个对象，同时也不会造成double free的错误。

一个通俗的理解
浅拷贝只是对指针的拷贝，拷贝后两个指针指向同一个内存空间，深拷贝不但对指针进行拷贝，而且对指针指向的内容进行拷贝，经深拷贝后的指针是指向两个不同地址的指针。
 */

#include <iostream>
 
class shallowCopy {
public:
    shallowCopy(int len) : m_len(len) {
        m_ptr = new int(0); // m_ptr指向一个值为0的int
    }
    shallowCopy() {}
 
    ~shallowCopy() {
        delete m_ptr;
    }
 
public: // 定义为public，方便输出
    int* m_ptr;
    int m_len;
};
 
class deepCopy {
public:
    deepCopy(int len) : m_len(len) {
        std::cout << "call deepCopy(int len) " << std::endl;
        m_ptr = new int(1);
    }
    deepCopy(const deepCopy& deepcopy) {
        std::cout << "call deepCopy(const deepCopy& deepcopy) " << std::endl;
        m_len = deepcopy.m_len;
        m_ptr = new int(*(deepcopy.m_ptr)); // 重新分配内存，并且赋值
    } // 拷贝构造函数

    /* TODO
    deepCopy(const deepCopy& ori) {
        m_len = ori.m_len;
        m_ptr = new int[m_len];
        for(int i = 0; i < m_len; i++) {
            m_ptr[i] = ori.m_ptr[i];
        }
    } */

    ~deepCopy() {
        delete m_ptr;
    }
 
public:
    int* m_ptr;
    int m_len;
};
 
int main() {
    shallowCopy sc(1);
    auto sc1 = sc; // 浅拷贝 执行完之后会调用析构函数来delete - 会报错 “free(): double free detected in tcache 2”
    std::cout << "shallowCopy: " << std::endl; // 执行完后，调用析构函数时会出错
    std::cout << "sc.m_ptr = " << sc.m_ptr << std::endl;
    std::cout << "sc1.m_ptr = " << sc1.m_ptr << std::endl;
 
    std::cout << "deepCopy: " << std::endl;
    deepCopy dc(1);
    deepCopy dc1(dc); // 深拷贝
    std::cout << "dc.m_ptr = " << dc.m_ptr << std::endl;
    std::cout << "dc1.m_ptr = " << dc1.m_ptr << std::endl;    
}




// another example of structor copy

class Book {
public:
    string Title;
    string Author;
    float* Rates;
    int RatesCounter;

    Book(string titles, string author) : Title(titles), Author(author) {
        cout << " - constructor - " << endl;
        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 5;
        Rates[1] = 4;
    }

    ~Book() {
        cout << " - destructor - " << endl;
        delete[] Rates;
        Rates = nullptr;
    }

    Book(const Book& original) {
        cout << " - copy constructor - " << endl;
        Title = original.Title;
        Author = original.Author;
        // Rates = original.Rates;
        RatesCounter = original.RatesCounter;

        Rates = new float[RatesCounter];
        for(int i = 0; i < RatesCounter; i++) {
            Rates[i] = original.Rates[i];
        }
    }
};

void printBook(Book book) {
    cout << "Title: " << book.Title << endl;
    cout << "Author: " << book.Author << endl;

    float sum = 0;
    for(int i = 0; i < book.RatesCounter; i++) {
        sum += book.Rates[i];
    }
    cout << "Avg rate: " << sum / book.RatesCounter << endl;
}

int main(void) {
    Book book1("A's book", "A");
    
    // Book book2("B's book", "B");
    Book book2(book1);
    // cout << book3.Rates[0] << ", " << book3.Rates[1] << endl;

    // Book book4 = book1;
    // cout << book4.Rates[0] << ", " << book4.Rates[1] << endl;

    printBook(book1);
    printBook(book2);

    return 0;
}