#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

class shallowCopy {
public:
    shallowCopy(int len) : m_len(len) {m_ptr = new int(0);}
    shallowCopy() {}

    ~shallowCopy() {cout << "out" << endl; delete m_ptr;}

public:
    int* m_ptr;
    int m_len;
};

class deepCopy {
public:
    deepCopy(int len) : m_len(len) {m_ptr = new int(1);}
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


int main(void) {
    deepCopy s1(4);  // 执行完之后会调用析构函数来delete
    auto s2 = s1;       // 执行完后，调用析构函数时会出错
    cout << *(s2.m_ptr) << endl;

    return 0;
}