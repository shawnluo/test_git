#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

class shallowCopy {
public:
    shallowCopy(int len) : m_len(len) {
        m_ptr = new int(0);
    }
    shallowCopy() {}

    ~shallowCopy() {
        delete m_ptr;
    }

public:
    int* m_ptr;
    int m_len;
};

class deepCopy {
public:
    deepCopy(int len) : m_len(len) {
        m_ptr = new int(1);
    }
    deepCopy(const deepCopy& ori) {
        m_len = ori.m_len;
        m_ptr = new int[m_len];
        for(int i = 0; i < m_len; i++) {
            m_ptr[i] = ori.m_ptr[i];
        }
    }
    ~deepCopy() {
        delete m_ptr;
    }

public:
    int* m_ptr;
    int m_len;
};

class Book {
public:
    string title;
    string author;
    float* rates;
    int ratesCounter;

    Book(string title, string author) {
        cout << " +++++++++++ " << endl;
        this->title = title;
        this->author = author;
        this->ratesCounter = 2;
        this->rates = new float[this->ratesCounter];
        this->rates[0] = 15;
        this->rates[1] = 4;
    }

    ~Book() {
        cout << " ---2--- " << endl;
        delete[] rates;
        rates = nullptr;
    }

    Book(const Book& original) {
        cout << " ------ " << endl;
        title = original.title;
        author = original.author;
        ratesCounter = original.ratesCounter;

        rates = new float[ratesCounter];
        for(int i = 0; i < ratesCounter; i++) {
            rates[i] = original.rates[i];
        }
    }
};

class Test {
public:
    int val = 10000;
    Test(int val) {
        // cout << val << endl;
        this->val = val;
    }

    ~Test() {
        cout << "- destructor - " << endl;
    }

    int get() const {
        cout << val << endl;
        return val;
    }
};

void foo(int num) {
    // for(int i = 0; i < num; i++) {
        cout << "in thread" << endl;
    // }
    Test t1(23);
    exit(0);
}

int main(void) {
    int n = 19;
    thread t1(foo, n);

    sleep(3);
    t1.join();

    // Book book1("Show me", "the money");
    // cout << 111 << endl;
    // Book book2(book1);
    // cout << 222 << endl;
    // for(auto i = 0; i < book2.ratesCounter; i++) {
    //     cout << book2.rates[i] << endl;
    // }
    // Test test(5);
    // test.get();

    // deepCopy s1(4);  // 执行完之后会调用析构函数来delete
    // auto s2 = s1;       // 执行完后，调用析构函数时会出错
    // cout << *(s2.m_ptr) << endl;

    // int i = 1;
    // cout << (i << 3) << endl;

    return 0;
}