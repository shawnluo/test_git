
#include "test.hpp"

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


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/*
    10 producers, 1 consumer
*/

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    int item = 0;
    
    while (1) {
        // Produce item
        item++;
        
        // Wait for an empty slot
        sem_wait(&empty);
        
        // Enter critical section
        pthread_mutex_lock(&mutex);
        
        // Add item to the buffer
        buffer[item % BUFFER_SIZE] = item;
        printf("Produced by thread %ld: %d\n", *(long*)arg, item);
        
        // Exit critical section
        pthread_mutex_unlock(&mutex);
        
        // Signal that a slot is full
        sem_post(&full);
        
        // Simulate some delay
        sleep(1);
    }
}

void *consumer(void *arg) {
    while (1) {
        // Wait for a full slot
        sem_wait(&full);
        
        // Enter critical section
        pthread_mutex_lock(&mutex);
        
        // Consume item from the buffer
        int item = buffer[*(int*)arg % BUFFER_SIZE];
        printf("Consumed by thread %ld: %d\n", *(long*)arg, item);
        
        // Exit critical section
        pthread_mutex_unlock(&mutex);
        
        // Signal that a slot is empty
        sem_post(&empty);
        
        // Simulate some delay
        sleep(2);
    }
}

int main() {
    pthread_t producer_thread, consumer_threads[3];
    
    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    // Create producer thread
    for (long i = 0; i < 3; i++) {
        pthread_create(&producer_thread, NULL, producer, (void*)&i);
    }
    
    // Create consumer threads
    for (long i = 0; i < 3; i++) {
        pthread_create(&consumer_threads[i], NULL, consumer, (void *)&i);
    }
    
    // Join threads
    for (int i = 0; i < 3; i++) {
        pthread_join(producer_thread, NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(consumer_threads[i], NULL);
    }
    
    // Cleanup
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
