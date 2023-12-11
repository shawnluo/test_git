#include <pthread.h>

#include <string.h>
#include <unistd.h>

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
int NUMS = 5;

void* producer(void* arg) {
    // TI* info = (TI*)arg;
    int i = (int)arg;
    for(;;) {
        // pthread_mutex_lock(&mutex);
        int ret = pthread_mutex_trylock(&mutex);
        if(ret != 0) {
            printf(" - in producer - %d - not lock\n", i);

            continue;
        }
        // pthread_testcancel();
        printf(" - in producer - %d\n", i);
    
        // sleep(1);
        condCount = (condCount + 1) % NUMS;

        pthread_mutex_unlock(&mutex);
        sleep(1);
        // pthread_cond_broadcast(&cond);
        // pthread_testcancel();
    }

    pthread_exit(NULL);
}

int main(void) {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t thread_id[NUMS];

    for(size_t i = 0; i < NUMS; i++) {
        // err = pthread_create(&tid[i], NULL, thread_func, (void*)&i); // 这里不能用i的地址。因为i是在变化的。最终会变到5。此时在子进程中只会指向5的地址。
        pthread_create(&thread_id[i], NULL, producer, (void*)i);
    }

    for(size_t i = 0; i < NUMS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);


    return 0;
}