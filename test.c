#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WAREHOUSE_CAPACITY 20
#define PRODUCER 3
#define CONSUMER 5

int warehouse = 0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t warehouse_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t warehouse_not_empty = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    printf("------ producer: %ld\n", *(long*)arg);
    while (1) {
        // Produce item

        pthread_mutex_lock(&mutex1);

        // Check if the warehouse is full
        while (warehouse == 10) {
            // Wait for the warehouse to not be full
            pthread_cond_wait(&warehouse_not_full, &mutex1);
        }

        // Add item to the warehouse
        warehouse++;

        printf("+ Producer %ld - warehouse: %d\n", *(long*)arg, warehouse);

        // Signal that the warehouse is not empty
        pthread_cond_signal(&warehouse_not_empty);

        pthread_mutex_unlock(&mutex1);

        // Simulate some delay
        int lower = 1;
        int upper = 5;
        int num = (rand() % 
            (upper - lower + 1)) + lower;
        usleep(num * 100000);
    }
}

void *consumer(void *arg) {
    printf("------ consumer: %ld\n", *(long*)arg);
    while (1) {
        pthread_mutex_lock(&mutex2);

        // Check if the warehouse is empty
        while (warehouse == 0) {
            // Wait for the warehouse to not be empty
            pthread_cond_wait(&warehouse_not_empty, &mutex2);
        }

        // Consume item from the warehouse
        warehouse--;
        printf("- Consumer %ld - warehouse: %d\n", *(long*)arg, warehouse);

        // Signal that the warehouse is not full
        pthread_cond_signal(&warehouse_not_full);

        pthread_mutex_unlock(&mutex2);

        // Simulate some delay

        int lower = 1;
        int upper = 5;
        int num = (rand() % 
            (upper - lower + 1)) + lower;
        usleep(num * 100000);
    }
}

int main() {
    pthread_t producer_threads[3], consumer_threads[3];

    // Create producer threads
    for (long i = 0; i < PRODUCER; i++) {
        pthread_create(&producer_threads[i], NULL, producer, (void *)&i);
    }

    // Create consumer threads
    for (long j = 0; j < CONSUMER; j++) {
        pthread_create(&consumer_threads[j], NULL, consumer, (void *)&j);
    }

    // Join threads
    for (int i = 0; i < PRODUCER; i++) {
        pthread_join(producer_threads[i], NULL);
    }

    for (int j = 0; j < CONSUMER; j++) {
        pthread_join(consumer_threads[j], NULL);
    }

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    pthread_cond_destroy(&warehouse_not_full);
    pthread_cond_destroy(&warehouse_not_empty);

    return 0;
}