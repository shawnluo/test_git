#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define WAREHOUSE_CAPACITY 20
#define BUFFER_SIZE 10

int warehouse[WAREHOUSE_CAPACITY];
int in = 0, out = 0, countx = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer_old(void *arg) {
    int item = 0;

    while (1) {
        // Produce item
        item++;

        // Wait for an empty slot in the warehouse
        sem_wait(&empty);

        // Enter critical section
        pthread_mutex_lock(&mutex);

        // Add item to the warehouse
        warehouse[in] = item;
        in = (in + 1) % WAREHOUSE_CAPACITY;
        countx++;
        printf("Produced: %d\n", item);

        // Exit critical section
        pthread_mutex_unlock(&mutex);

        // Signal that a slot in the warehouse is full
        sem_post(&full);

        // Simulate some delay
        sleep(1);
    }
}

void *producer(void *arg) {
    int item = 0;

    while (1) {
        // Produce item
        item++;

        // Wait for an empty slot in the warehouse
        sem_wait(&empty);

        // Enter critical section
        pthread_mutex_lock(&mutex);

        // Check if the warehouse is full, and wait for consumers
        while (countx == WAREHOUSE_CAPACITY) {
            pthread_mutex_unlock(&mutex);
            // Simulate some delay before checking again
            sleep(1);
            pthread_mutex_lock(&mutex);
        }

        // Add item to the warehouse
        warehouse[in] = item;
        in = (in + 1) % WAREHOUSE_CAPACITY;
        countx++;
        printf("Produced: %d\n", item);

        // Exit critical section
        pthread_mutex_unlock(&mutex);

        // Signal that a slot in the warehouse is full
        sem_post(&full);

        // Simulate some delay
        sleep(1);
    }
}


void *consumer(void *arg) {
    while (1) {
        // Wait for a full slot in the warehouse
        sem_wait(&full);

        // Enter critical section
        pthread_mutex_lock(&mutex);

        // Consume item from the warehouse
        int item = warehouse[out];
        out = (out + 1) % WAREHOUSE_CAPACITY;
        countx--;
        printf("Consumed by thread %ld: %d\n", (long)arg, item);

        // Exit critical section
        pthread_mutex_unlock(&mutex);

        // Signal that a slot in the warehouse is empty
        sem_post(&empty);

        // Simulate some delay
        sleep(2);
    }
}

int main() {
    pthread_t producer_thread, consumer_threads[3];

    // Initialize semaphores and mutex
    sem_init(&empty, 0, WAREHOUSE_CAPACITY);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer thread
    pthread_create(&producer_thread, NULL, producer, NULL);

    // Create consumer threads
    for (long i = 0; i < 3; i++) {
        pthread_create(&consumer_threads[i], NULL, consumer, (void *)i);
    }

    // Join threads
    pthread_join(producer_thread, NULL);
    for (int i = 0; i < 3; i++) {
        pthread_join(consumer_threads[i], NULL);
    }

    // Cleanup
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
