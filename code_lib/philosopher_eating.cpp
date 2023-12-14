#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m[5];

void* tfn(void* arg) {
    int i = (long)arg;
    int left, right;
    if (i == 4) {
        // 防止震荡现象发生。
        left  = 0;
        right = i;
    } else {
        left  = i;
        right = i + 1;
    }
    while (1) {
        pthread_mutex_lock(&m[left]);
        int ret = pthread_mutex_trylock(&m[right]);
        if (ret != 0) {
            // 尝试拿右手筷子失败，把左手的筷子释放
            pthread_mutex_unlock(&m[left]);
            printf("哲学家%d没有抢到筷子...\n", i);
            sleep(1);
            continue;
        }
        // 拿到了两支筷子
        // 吃面
        printf("哲学家%d正在吃面...\n", i);
        sleep(1);
        // 吃完面，释放筷子.
        pthread_mutex_unlock(&m[left]);
        pthread_mutex_unlock(&m[right]);
        // sleep(1);
    }
}

int main() {
    pthread_t pth[5];
    // 初始化五把锁
    for (int i = 0; i < 5; i++) {
        pthread_mutex_init(&m[i], NULL);
    }
    // 创建5个线程，相当于5个哲学家
    for (int i = 0; i < 5; i++) {
        pthread_create(&pth[i], NULL, tfn, (void*)i);
    }
    // 回收子线程
    for (int i = 0; i < 5; i++) {
        pthread_join(pth[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_mutex_destroy(&m[i]);
    }
    // 退出
    pthread_exit(NULL);
}