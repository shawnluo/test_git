#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_cond_t cond;
pthread_mutex_t mutex;
void* Routine1(void* arg) {
    //被调度线程执行
    while(1) {
        pthread_cond_wait(&cond, &mutex);
        printf("%s is running...\n", (char*)arg);
    }
}

void* Routine2(void* arg) {
    int cnt = 0;
    while(1) {
        if(cnt%3 != 0) {
            printf("signal\n");
            pthread_cond_signal(&cond); //唤醒等待队列中的首个线程
        }
        else {
            printf("multi\n");
            pthread_cond_broadcast(&cond);  //唤醒等待队列中的全部线程
        }
        cnt++;
        sleep(1);
    }
}

int main() {
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);

    pthread_t tid1,tid2,tid3,tid4;
    pthread_create(&tid1, NULL, Routine1, (void*)"thread 1");
    pthread_create(&tid2, NULL, Routine1, (void*)"thread 2");
    pthread_create(&tid3, NULL, Routine1, (void*)"thread 3");
    pthread_create(&tid4, NULL, Routine2, (void*)"thread signal");

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}