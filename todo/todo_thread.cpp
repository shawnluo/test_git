#include <pthread.h>
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

typedef struct thread_info {
    pthread_t thread_id;
    int thread_argNum;
    unsigned int delay;
    string message;
} TI;   // thread info

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
int condCount = 0;
int NUMS = 0;

void* producer(void* arg) {
    TI* info = (TI*)arg;

    for (;;) {
        pthread_mutex_lock(&mutex);
        while (condCount != info->thread_argNum) {
            /*  pthread_cond_wait
                1. 如果cond1 没有被发出（没有其他任务调用pthread_cond_signal(&cond1)），那么此线程就会一直等待，不会返回！
                2. 如果有其他任务调用pthread_cond_signal(&cond1), pthread_cond_wait就会返回。
                3. 在其等待期间，lock1会被释放
                4. 在其返回时，lock1会被重新锁定。直到pthread_mutex_unlock(&lock1)被调用，lock1才会被释放
             */
            pthread_cond_wait(&cond, &mutex);
        }
        for (int i = 0; i < 5; i++) {
            // pthread_testcancel();
            cout << " - in producer - " << info->message << " produce: " << i << endl;
        }
        sleep(info->delay);
        condCount = (condCount + 1) % NUMS;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
        pthread_testcancel();
    }

    pthread_exit(NULL);
}

int main(void) {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    vector<TI> tRunner;

    TI myThreadInfo;

    myThreadInfo.thread_argNum = 0;
    myThreadInfo.delay = 2;
    myThreadInfo.message = "Alice";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 1;
    myThreadInfo.delay = 1;
    myThreadInfo.message = "Bob";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 2;
    myThreadInfo.delay = 2;
    myThreadInfo.message = "Charli";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 3;
    myThreadInfo.delay = 3;
    myThreadInfo.message = "David";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 4;
    myThreadInfo.delay = 4;
    myThreadInfo.message = "Eva";
    tRunner.push_back(myThreadInfo);

    NUMS = tRunner.size();
    cout << NUMS << endl;

    for(size_t i = 0; i < NUMS; i++) {
        // err = pthread_create(&tid[i], NULL, thread_func, (void*)&i); // 这里不能用i的地址。因为i是在变化的。最终会变到5。此时在子进程中只会指向5的地址。
        pthread_create(&tRunner[i].thread_id, NULL, producer, &tRunner[i]);
    }

    sleep(5);
    for(size_t i = 0; i < NUMS; i++) {
        cout << " - main - cancel: " << tRunner[i].thread_argNum << endl;
        pthread_cancel(tRunner[i].thread_id);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    for(size_t i = 0; i < NUMS; i++) {
        pthread_join(tRunner[i].thread_id, NULL);
    }

    return 0;
}