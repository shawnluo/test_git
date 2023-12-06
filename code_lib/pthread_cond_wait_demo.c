#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

// declaring mutex
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

int done = 1;
int flag = 0;

void* foo1(void* arg) {\
    pthread_mutex_lock(&lock1); // acquire a lock1
    if (done == 1) {
        // let's wait on condition variable cond1
        done = 2;
        printf("Waiting on condition variable cond1\n");
        pthread_cond_wait(&cond1, &lock1);      // 1. 如果cond1 没有被发出（没有其他任务调用pthread_cond_signal(&cond1)），那么此线程就会一直等待，不会返回！
                                                // 2. 如果有其他任务调用pthread_cond_signal(&cond1), pthread_cond_wait就会返回。
                                                // 3. 在其等待期间，lock1会被释放
                                                // 4. 在其返回时，lock1会被重新锁定。直到pthread_mutex_unlock(&lock1)被调用，lock1才会被释放
    }
    
    pthread_mutex_unlock(&lock1);   // release lock1

    printf("Returning thread %ld\n", *(long*)arg);

    return NULL;
}

void* foo2(void* arg) {
    pthread_mutex_lock(&lock1); // acquire a lock1
    if (done == 2) {
        printf("Signaling condition variable cond1\n");
        pthread_cond_signal(&cond1);    // wake up sleeping/waiting thread
    }
    // release lock1
    pthread_mutex_unlock(&lock1);

    printf("Returning thread %ld\n", *(long*)arg);

    return NULL;
}

void* foo3(void* arg) {
    // acquire a lock1
    pthread_mutex_lock(&lock1);
    while(flag == 0) {

        sleep(1);
    }
    printf(" - pthread 3 - flag == 1\n");
    pthread_mutex_unlock(&lock1);

    return NULL;
}


int main() {
    pthread_t tid1, tid2, tid3;

    long parm1 = 1l;
    pthread_create(&tid1, NULL, foo1, (void*)&parm1);

    sleep(1);

    long parm2 = 2l;
    pthread_create(&tid2, NULL, foo2, (void*)&parm2);

    // pthread_create(&tid3, NULL, foo3, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    // pthread_join(tid3, NULL);
    
    return 0;
}