
#include "test.hpp"

sem_t emptyBuffer;
sem_t fullBuffer;
mutex g_mutex;
queue<int> buffer;

void producer(int i) {
    while (1) {
        sem_wait(&emptyBuffer);
        g_mutex.lock();

        int id = (rand() % 100);
        buffer.push(id);
        cout << "生产者放入 " << id << endl;

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
        cout << "消费者取出 " << ret << endl;

        g_mutex.unlock();
        sem_post(&emptyBuffer);
    }
}

int main() {
    sem_init(&emptyBuffer, 0, 1);
    sem_init(&fullBuffer, 0, 0);

    thread p1(producer, 3);
    thread p2(customer, 2);

    p1.join();
    p2.join();

    sem_destroy(&fullBuffer);
    sem_destroy(&emptyBuffer);

    return 0;
}
