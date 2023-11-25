#include "test.hpp"


#include <iostream>

using namespace std;

/*
 * ThreadCancel.c
 *
 *  Created on: Aug 17, 2013
 *      Author: root
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>

#define NUM_THREADS 5
void* search(void *);
void print_it(void*);

pthread_t threads[NUM_THREADS];
pthread_mutex_t lock;
int tries;
int started;
int main(){
    int i, pid;
    pid = getpid();
    printf("Search for the number=%d...\n", pid);
    pthread_mutex_init(&lock,NULL);
    for(started=0;started<NUM_THREADS; started++){
        pthread_create(&threads[started], NULL, search, (void*)pid);
    }
    for(i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("It took %d tries to find the number.\n", tries);
    return 0;
}

void print_it(void * arg){
    int *try = (int *)arg;
    pthread_t tid;
    tid = pthread_self();
    printf("Thread %lx was canceled on its %d try.\n", tid, *try);
}

void * search(void * arg){
    int num = (int)arg;
    int i,j,ntries;
    pthread_t tid;
    tid = pthread_self();
    while(pthread_mutex_trylock(&lock) == EBUSY){
        pthread_testcancel();                            //thread may be canceled and call cancel function handler !
    }
    printf("current thread tid:%lx.\n", tid);
    srand((int)tid);
    printf("current thread tid:%lx, after srand method.\n", tid);
    i = rand() & 0xFFFFFF;
    pthread_mutex_unlock(&lock);
    ntries = 0;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    while(started < NUM_THREADS){
        sched_yield();
    }
    pthread_cleanup_push(print_it, (void*)&ntries);
    while(1){
        i = (i+1) & 0xffffff;
        ntries++;
        if(num == i){
            while(pthread_mutex_trylock(&lock) == EBUSY){
                printf("Thread %lx found the number! But not get lock!\n", tid);
                pthread_testcancel();
            }
            tries = ntries;
            printf("Thread %lx found the number!\n", tid);
            for(j=0;j<NUM_THREADS;j++){
                if(threads[j] != tid){
                    pthread_cancel(threads[j]);
                }
            }
            break;
        }

        if(ntries %100 ==0){
            pthread_testcancel();
        }
    }

    pthread_cleanup_pop(0);
    return ((void*)0);
}