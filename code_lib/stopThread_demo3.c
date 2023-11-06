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
