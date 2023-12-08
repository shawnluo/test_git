
#include "test.hpp"

#include <semaphore.h>
#include <unistd.h>
using namespace std;


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

/*
    10 producers, 1 consumer
*/


/*信号量实现 多生产者 多消费者问题*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM 5

int queue_[NUM];                    // 全局数组实现环形队列
sem_t blank_number, product_number; // 空格数信号量, 产品数信号量

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

int prodeucer_i = 0;
int consumer_i  = 0;
void* producer(void* arg) {
    while (1) {
        sem_wait(&blank_number); // 生产者将空格子数--,为0则阻塞等待
        pthread_mutex_lock(&mutex1);
        int data            = rand() % 1000 + 1;
        queue_[prodeucer_i] = data;                    // 生产一个产品
        prodeucer_i         = (prodeucer_i + 1) % NUM; // 借助下标实现环形
        pthread_mutex_unlock(&mutex1);
        sem_post(&product_number); // 将产品数++

        printf("----Produce%d---%d\n", *(int*)arg, data);

        sleep(rand() % 3);
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&product_number); // 消费者将产品数--,为0则阻塞等待
        pthread_mutex_lock(&mutex2);
        int data           = queue_[consumer_i];
        queue_[consumer_i] = 0; // 消费一个产品
        consumer_i         = (consumer_i + 1) % NUM;
        pthread_mutex_unlock(&mutex2);
        sem_post(&blank_number); // 消费掉以后,将空格子数++

        printf("-Consume%d---%d\n", *(int*)arg, data);


        sleep(rand() % 3);
    }
}

int main(int argc, char* argv[]) {
    pthread_t pid1, pid2, cid1, cid2;

    sem_init(&blank_number, 0, NUM); // 初始化空格子信号量为5
    sem_init(&product_number, 0, 0); // 产品数为0

    int i = 1;
    pthread_create(&pid1, NULL, producer, (void*)&i);
    i = 2;
    pthread_create(&pid2, NULL, producer, (void*)&i);
    i = 3;
    pthread_create(&cid1, NULL, consumer, (void*)&i);
    i = 4;
    pthread_create(&cid2, NULL, consumer, (void*)&i);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(cid1, NULL);
    pthread_join(cid2, NULL);

    sem_destroy(&blank_number);
    sem_destroy(&product_number);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
