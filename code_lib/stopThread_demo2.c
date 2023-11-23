

// 2. pthread_cancel 用来发出cancel请求，来终结某线程

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    while(1) {
        printf("Thread is running\n");      // 1. printf 是退出点
        sleep(1);                           // 2. sleep是退出点。pthread_cancel发出后，会在这退出。
        pthread_testcancel();               // 3. 这也是退出点
        printf("Thread xx is running\n");   // pthread_cancel发出后，这不会被执行
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

