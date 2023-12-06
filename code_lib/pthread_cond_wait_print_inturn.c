

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
/* 
    两种初始化的方法
    方法一：
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    方法二：
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&cond, NULL); 
*/

pthread_mutex_t mutex;
pthread_cond_t cond;


void* thread_func(void* arg) {
    int param = *(int*)arg;
    char c    = 'A' + param;
    int ret, i = 0;

    for (; i < 5; i++) {
        pthread_mutex_lock(&mutex);
        while (param != n) {
            /*  pthread_cond_wait
                1. 如果cond1 没有被发出（没有其他任务调用pthread_cond_signal(&cond1)），那么此线程就会一直等待，不会返回！
                2. 如果有其他任务调用pthread_cond_signal(&cond1), pthread_cond_wait就会返回。
                3. 在其等待期间，lock1会被释放
                4. 在其返回时，lock1会被重新锁定。直到pthread_mutex_unlock(&lock1)被调用，lock1才会被释放
             */
            ret = pthread_cond_wait(&cond, &mutex);
            if (ret != 0) {
                printf("thread %d wait failed:%s\n", param, strerror(ret));
            }
        }
        // printf("%d ",param+1);
        printf("%c ", c);
        n = (n + 1) % NUM;
        pthread_mutex_unlock(&mutex);

        /* if thread maore than 2, then must use pthread_cond_broadcast(&cond);
            pthread_cond_signal only wake up one thread. Not sure which one will be woken up.
         */
        pthread_cond_broadcast(&cond);
        // pthread_cond_signal(&cond);
    }
    return (void*)0;
}

int main(int argc, char** argv) {
    int i = 0, err;
    pthread_t tid[NUM];
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (; i < NUM; i++) {
        err = pthread_create(&tid[i], NULL, thread_func, (void*)&i);
        usleep(100);
        if (err != 0) {
            printf("thread_create error: %s\n", strerror(err));
            exit(-1);
        }
    }
    for (i = 0; i < NUM; i++) {
        err = pthread_join(tid[i], NULL);
        if (err != 0) {
            printf("can not join with thread %d: %s\n", i, strerror(err));
            exit(-1);
        }
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    printf("\n");
    return 0;
}