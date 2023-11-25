#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*
 * ThreadCancel.c
 *
 *  Created on: Aug 17, 2013
 *      Author: root
 */
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    int n = 0;
    int i, rs;
    // rs = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    rs = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if (rs != 0) {
        perror("Thread pthread_setcancelstate failed\n");
        exit(EXIT_FAILURE);
    }

    // PTHREAD_CANCEL_DEFERRED means that it will wait the pthread_join, 
    // pthread_cond_wait, pthread_cond_timewait.. to be call when the 
    // thread receive cancel message.
    rs = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    if (rs != 0) {
        perror("Thread pthread_setcanceltype failed\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // printf("Thread is running\n");
        // sleep(5);   // sleep是退出点。pthread_cancel发出后，会在这退出。

        printf("Thread is running\n");      // 1. printf 是退出点
        sleep(1);                           // 2. sleep是退出点。pthread_cancel发出后，会在这退出。
        pthread_testcancel();               // 3. 这也是退出点
        printf("Thread xx is running\n");   // pthread_cancel发出后，这不会被执行

        // printf("Thread xx is running\n");   // pthread_cancel发出后，这不会不执行
        // int i = 0;
        // for(int i = 0; i < 100000000; i++) {
        //     for(int j = 0; j < 10000000; j++) {
        //         for(int k = 0; k < 100000; k++) {
        //             printf("n = %d, ", n);
        //             // pthread_testcancel();
        //         }
        //     }
        //     n++;
        //     // printf("n = %d, ", n);
        // }
        // pthread_testcancel();
        // printf("n = %d, ", n);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    
    // Let the thread run for 3 seconds
    sleep(3);
    
    // Request cancellation of the thread
    pthread_cancel(thread);
    
    // Wait for the thread to exit
    pthread_join(thread, NULL);
    
    printf("Thread is canceled\n");
    return 0;
}