

// 1. pthread_exit 用来终结自己所在线程

#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread is running\n");
    pthread_exit(NULL); // Terminate the thread
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    
    // Wait for the thread to exit
    pthread_join(thread, NULL);
    
    printf("Thread is terminated\n");
    return 0;
}


