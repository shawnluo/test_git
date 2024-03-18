#include "../test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

class FizzBuzz {
private:
    int n;
    int cur;
    sem_t sem_fizz;
    sem_t sem_buzz;
    sem_t sem_fizz_buzz; // 这三个信号量分别用于线程的同步
    sem_t sem_num;       // 用于触发数字增加

public:
    FizzBuzz(int n) {
        this->n = n;
        cur     = 0;
        sem_init(&sem_fizz, 0, 0);
        sem_init(&sem_buzz, 0, 0);
        sem_init(&sem_fizz_buzz, 0, 0); // 这三者的信号量初始化都置位为0，三个线程均被阻塞
        sem_init(&sem_num, 0, 1);       // 初始化信号量为1，触发开始
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (cur <= n) {
            sem_wait(&sem_fizz); // 等待信号量为1
            if (cur > n) break;
            printFizz();
            sem_post(&sem_num); // 将信号量sem_num加1,变为1
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (cur <= n) {
            sem_wait(&sem_buzz);
            if (cur > n) break;
            printBuzz();
            sem_post(&sem_num);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (cur <= n) {
            sem_wait(&sem_fizz_buzz);
            if (cur > n) break;
            printFizzBuzz();
            sem_post(&sem_num);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (++cur <= n) {
            sem_wait(&sem_num); // 等待信号量sem_num变为1
            if (cur % 3 == 0 && cur % 5 == 0) {
                sem_post(&sem_fizz_buzz); // 将sem_fizz_buzz置为1
            } else if (cur % 3 == 0) {
                sem_post(&sem_fizz); // 将sem_fizz置为1
            } else if (cur % 5 == 0) {
                sem_post(&sem_buzz); // 将sem_buzz置为1
            } else {
                printNumber(cur);
                sem_post(&sem_num); // 将sem_num置为1
            }
        }

        // 以下三个post通过更新sem_fizz等信号量，调动其他线程运行，进而结束所有线程
        sem_post(&sem_fizz);
        sem_post(&sem_buzz);
        sem_post(&sem_fizz_buzz);
    }
};

int main(int argc, char** argv) {
    FizzBuzz fizzBuzz(15);

    std::function<void()> printFizz     = []()      { cout << " fizz "       << endl; };
    std::function<void()> printBuzz     = []()      { cout << " buzz "       << endl; };
    std::function<void()> printFizzBuzz = []()      { cout << " fizzbuzz "   << endl; };
    std::function<void(int)> printNum   = [](int x) { cout << x              << endl; };

    std::thread th[4];
    th[0] = std::thread(&FizzBuzz::fizz, &fizzBuzz, printFizz);
    th[1] = std::thread(&FizzBuzz::buzz, &fizzBuzz, printBuzz);
    th[2] = std::thread(&FizzBuzz::fizzbuzz, &fizzBuzz, printFizzBuzz);
    th[3] = std::thread(&FizzBuzz::number, &fizzBuzz, printNum);

    for (auto& ts : th) {
        if (ts.joinable()) ts.join();
    }

    return 0;
}
