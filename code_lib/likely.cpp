#include "test.hpp"
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)


void func_not_throw() noexcept { // noexcept: 就算符合条件，也不会被catch
    throw 1;
}

void func_throw() {
    // char c = 'a';
    int c = 0;
    throw c;    // c如果是char, 在catch(char)中就会被catch
                // c如果是int , 在catch(int)中就会被catch
}

int test() {
    int i = 10;
    if(likely(i == 1)) {
        cout << "yes" << endl;
    } else if(unlikely(i == 10)) {
        cout << 10 << endl;
        throw std::exception();
    }
    return 0;
}

int test2() {
    try {
        func_not_throw(); // 直接 terminate，不会被 catch
    } catch (int) {
        cout << "catch int" << endl;
    }
    return 0;
}


int test3() {
    try {
        func_throw();   // 被 catch
    } catch (int) {
        cout << "catch int" << endl;
    } catch (char) {
        cout << "catch char" << endl;
    }
    return 0;
}

int main(void) {
    test3();

    return 0;
}