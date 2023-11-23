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
    while(1) {
        printf("Thread is running\n");
        sleep(1);   // sleep是退出点。pthread_cancel发出后，会在这退出。
        // printf("Thread xx is running\n");   // pthread_cancel发出后，这不会不执行
        // int i = 0;
        for(int i = 0; i < 100000000; i++) {
            for(int j = 0; j < 10000000; j++) {
                for(int k = 0; k < 100000; k++) {
                    printf("n = %d, ", n);
                    // pthread_testcancel();
                }
            }
            n++;
            // printf("n = %d, ", n);
        }
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