

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


// 2. pthread_cancel 用来发出cancel请求，来终结某线程

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    while(1) {
        printf("Thread is running\n");
        sleep(1);   // sleep是退出点。pthread_cancel发出后，会在这退出。
        printf("Thread xx is running\n");   // pthread_cancel发出后，这不会不执行
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

// 3. pthread_kill 向特定目标线程发出信号，目标线程中注册信号处理函数，来对收到的信号定义处理函数

#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signo) {
    if (signo == SIGTERM) {
        printf("Thread received SIGTERM signal. Exiting...\n");
        pthread_exit(NULL);
    }
}

void *thread_function(void *arg) {
    signal(SIGTERM, signal_handler); // Register signal handler
    while(1) {
        printf("Thread is running\n");
        sleep(1);
    }
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    
    // Let the thread run for 3 seconds
    sleep(3);
    
    // Send SIGTERM signal to the thread
    pthread_kill(thread, SIGTERM);
    
    // Wait for the thread to exit
    pthread_join(thread, NULL);
    
    printf("Thread is terminated\n");
    return 0;
}
