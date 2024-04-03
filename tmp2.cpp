
#include "test.hpp"

sem_t emptyBuffer;
sem_t fullBuffer;
mutex g_mutex;
queue<int> buffer; // 全局变量

/*
    1. sem_init 初始值的意义？
        可以初始化 n 个生产者，或者 n 个消费者。相应建立 n 个进程

    2. g_mutex.lock() 存在的意义？
        防止 producer() 和 customer() 被被多个线程同时访问。

    3. 两个semaphore 同时存在的意义？
        分别是 生产者 sem 和 消费者 sem。用于同步两个线程：消费者执行完之后，再执行生产者；生产者执行完之后，再执行消费者。

    4. sem 和 lock 一起联合使用的目的？
        通过上述问题，答案显而易见：
            1）. lock: 同一个线程如果执行同一个函数，用lock来保证同一时刻，只有一个线程进入执行。
            2）. sem:  保证生产者和消费者线程的执行顺序，也就是synchnization.
 */

void kmp() {

}

int main(void) {


    return 0;
}