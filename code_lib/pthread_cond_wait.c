
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#include <pthread.h>
#include <unistd.h>

#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 

// Declaration of thread condition variable 
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 

// declaring mutex 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

// Thread function 
void releaseFun() { 
    // Let's signal condition variable cond
    printf("Signaling condition variable cond\n"); 
    pthread_cond_signal(&cond); 
}

// Thread function 
void* blockedThread() {
    // acquire a lock 
    pthread_mutex_lock(&lock); 
    printf("Waiting on condition variable cond\n");
    pthread_cond_wait(&cond, &lock); 
    // release lock 
    pthread_mutex_unlock(&lock); 

    printf("Returning thread\n"); 

    return NULL; 
}    

// Driver code 
int main() {
    pthread_t tid;

    // Create thread 1 
    pthread_create(&tid, NULL, blockedThread, NULL); 

    // sleep for 1 sec so that thread 1
    // would get a chance to run first
    sleep(1);

    releaseFun();
    // wait for the completion of thread 2
    pthread_join(tid, NULL);

    return 0;
}