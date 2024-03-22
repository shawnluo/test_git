
#include "../test.hpp"

sem_t emptyBuffer;
sem_t fullBuffer;
mutex g_mutex;
queue<int> buffer;  // 全局变量

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


void producer(int i) {
    while (1) {
        sem_wait(&emptyBuffer);
        g_mutex.lock();

        int id = (rand() % 100);
        buffer.push(id);
        cout << " + 生产者 " << i << " 放入 " << id << "    ";
        
        for(int x = 0; x < 10; x++) cout << x << " ";
        cout << endl; 

        g_mutex.unlock();
        sem_post(&fullBuffer);
        
        sleep(1);
    }
}

void customer(int i) {
    while (1) {
        sem_wait(&fullBuffer);
        g_mutex.lock();

        int ret = buffer.front();
        buffer.pop();
        cout << "                                               - 消费者 " << i << " 取出 " << ret << endl;

        g_mutex.unlock();
        sem_post(&emptyBuffer);

        usleep(2000);
    }
}

int main() {
    sem_init(&emptyBuffer, 0, 3);   // initilize to 1, then producer is able to run first
    sem_init(&fullBuffer, 0, 0);

    thread p1(producer, 1);
    thread p2(producer, 2);
    thread p3(producer, 3);
    thread p10(customer, 10);

    p1.join();
    p2.join();
    p3.join();
    p10.join();

    sem_destroy(&fullBuffer);
    sem_destroy(&emptyBuffer);

    return 0;
}
