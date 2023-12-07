#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WAREHOUSE_CAPACITY 20

int warehouse[WAREHOUSE_CAPACITY];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t warehouse_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t warehouse_not_empty = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    int item = 0;

    while (1) {
        // Produce item
        item++;

        pthread_mutex_lock(&mutex);

        // Check if the warehouse is full
        while (count == WAREHOUSE_CAPACITY) {
            // Wait for the warehouse to not be full
            pthread_cond_wait(&warehouse_not_full, &mutex);
        }

        // Add item to the warehouse
        warehouse[count] = item;
        count++;
        printf("Produced: %d\n", item);

        // Signal that the warehouse is not empty
        pthread_cond_signal(&warehouse_not_empty);

        pthread_mutex_unlock(&mutex);

        // Simulate some delay
        sleep(1);
    }
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        // Check if the warehouse is empty
        while (count == 0) {
            // Wait for the warehouse to not be empty
            pthread_cond_wait(&warehouse_not_empty, &mutex);
        }

        // Consume item from the warehouse
        int item = warehouse[count - 1];
        count--;
        printf("Consumed by thread %ld: %d\n", (long)arg, item);

        // Signal that the warehouse is not full
        pthread_cond_signal(&warehouse_not_full);

        pthread_mutex_unlock(&mutex);

        // Simulate some delay
        sleep(2);
    }
}

int main() {
    pthread_t producer_threads[3], consumer_threads[3];

    // Create producer threads
    for (long i = 0; i < 3; i++) {
        pthread_create(&producer_threads[i], NULL, producer, (void *)i);
    }

    // Create consumer threads
    for (long i = 0; i < 3; i++) {
        pthread_create(&consumer_threads[i], NULL, consumer, (void *)i);
    }

    // Join threads
    for (int i = 0; i < 3; i++) {
        pthread_join(producer_threads[i], NULL);
        pthread_join(consumer_threads[i], NULL);
    }

    pthread_cond_destroy(&warehouse_not_full);
    pthread_cond_destroy(&warehouse_not_empty);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}