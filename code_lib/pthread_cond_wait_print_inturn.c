

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <unistd.h>

/* 四、编写一个程序，开启3个线程，
    这3个线程的ID分别为A、B、C，
    每个线程将自己的ID在屏幕上打印10遍，
    要求输出结果必须按ABC的顺序显示；如：ABCABC….依次递推。 */

// #define DEBUG

#define NUM 3

int n                  = 0;
pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER; //互斥量
pthread_cond_t qready  = PTHREAD_COND_INITIALIZER;  //条件变量

void* thread_func(void* arg) {
    int param = (int)arg;
    char c    = 'A' + param;
    int ret, i = 0;

    for (; i < 3; i++) {
        pthread_mutex_lock(&mylock);
        while (param != n) {
#ifdef DEBUG
            printf("thread %d waiting\n", param);
#endif
            ret = pthread_cond_wait(&qready, &mylock);
            if (ret == 0) {
#ifdef DEBUG
                printf("thread %d wait success\n", param);
#endif
            } else {
#ifdef DEBUG
                printf("thread %d wait failed:%s\n", param, strerror(ret));
#endif
            }
        }
        // printf("%d ",param+1);
        printf("%c ", c);
        n = (n + 1) % NUM;
        pthread_mutex_unlock(&mylock);
        pthread_cond_broadcast(&qready); // if thread maore than 2, then must use pthread_cond_broadcast(&qready);
        // pthread_cond_signal(&qready); // pthread_cond_signal only wake up one thread. Not sure which one will be woken up.
    }
    return (void*)0;
}

int main(int argc, char** argv) {
    int i = 0, err;
    pthread_t tid[NUM];
    void* tret;

    for (; i < NUM; i++) {
        err = pthread_create(&tid[i], NULL, thread_func, (void*)i);
        if (err != 0) {
            printf("thread_create error:%s\n", strerror(err));
            exit(-1);
        }
    }
    for (i = 0; i < NUM; i++) {
        err = pthread_join(tid[i], &tret);
        if (err != 0) {
            printf("can not join with thread %d:%s\n", i, strerror(err));
            exit(-1);
        }
    }
    printf("\n");
    return 0;
}