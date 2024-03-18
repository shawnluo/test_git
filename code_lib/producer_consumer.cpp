
#include "../test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

#include <iostream>
#include <string>

#include <iostream>
#include <pthread.h>
#include <queue>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t emptyBuffer;
sem_t fullBuffer;
// pthread_mutex_t mutex;
mutex g_mutex;
queue<int> buffer;

void producer(void* arg) {
    while (1) {
        sem_wait(&emptyBuffer);
        // pthread_mutex_lock(&mutex);
        g_mutex.lock();
        int id = (rand() % 100);
        buffer.push(id);
        printf("生产者放入:%d\n", id);
        // pthread_mutex_unlock(&mutex);
        g_mutex.unlock();
        sem_post(&fullBuffer);
        sleep(1);
    }
}

void* customer(void* arg) {
    while (1) {
        sem_wait(&fullBuffer);
        // pthread_mutex_lock(&mutex);
        g_mutex.lock();
        int ret = buffer.front();
        buffer.pop();
        printf("消费者取出:%d\n", ret);
        // pthread_mutex_unlock(&mutex);
        g_mutex.unlock();
        sem_post(&emptyBuffer);
    }
}

int main() {
    // pthread_mutex_init(&mutex, NULL);
    sem_init(&emptyBuffer, 0, 1);
    sem_init(&fullBuffer, 0, 0);

    cout << "111" << endl;

    pthread_t p1, p2;
    pthread_create(&p1, NULL, producer, NULL);
    pthread_create(&p2, NULL, customer, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    sem_destroy(&fullBuffer);
    sem_destroy(&emptyBuffer);
    // pthread_mutex_destroy(&mutex);
}
