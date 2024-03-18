#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int stopFlag = 0;

void* firstThread(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (stopFlag) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
        
        // Perform the first thread's task here
        printf("First Thread is running...\n");
        sleep(1);
    }
    printf("First Thread stopped.\n");
    return NULL;
}

void* secondThread(void* arg) {
    sleep(5); // Wait for 5 seconds
    pthread_mutex_lock(&mutex);
    stopFlag = 1;
    pthread_mutex_unlock(&mutex);
    printf("Second Thread stopped the First Thread.\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_mutex_init(&mutex, NULL);
    
    // Create and start the first thread
    pthread_create(&thread1, NULL, firstThread, NULL);
    
    // Create and start the second thread
    pthread_create(&thread2, NULL, secondThread, NULL);
    
    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}

// ===================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t firstThread, secondThread;

void* firstThreadTask(void* arg) {
    while (1) {
        printf("First Thread is running...\n");
        sleep(1);
    }
    printf("First Thread stopped.\n");
    return NULL;
}

void* secondThreadTask(void* arg) {
    sleep(5); // Wait for 5 seconds
    pthread_cancel(firstThread);
    printf("Second Thread stopped the First Thread.\n");
    return NULL;
}

int main() {
    // Create and start the first thread
    pthread_create(&firstThread, NULL, firstThreadTask, NULL);

    // Create and start the second thread
    pthread_create(&secondThread, NULL, secondThreadTask, NULL);

    // Wait for the first thread to finish
    pthread_join(firstThread, NULL);

    return 0;
}

// ================================================


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#include <pthread.h>
#include <unistd.h>

#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 

// #include <linux/delay.h>

// Declaration of thread condition variable 
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 

// declaring mutex 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

// Thread function 
void releaseFun() { 
    // Let's signal condition variable cond
    printf("Signaling condition variable cond\n"); 
    pthread_cond_signal(&cond); 
}

// Thread function 
void* blockedThread(void *data) {
    // acquire a lock 
    int sleepTime = data;
    printf("%d\n", sleepTime);
    sleep(sleepTime);
    pthread_mutex_lock(&lock); 
    printf("Waiting on condition variable cond\n");
    pthread_cond_wait(&cond, &lock); 
    // release lock 
    pthread_mutex_unlock(&lock); 

    printf("Returning thread\n"); 

    return NULL; 
}    

// Driver code 
int main() {
    pthread_t tid1, tid2;

    // Create thread 1 
    int freq = 1;
    pthread_create(&tid1, NULL, blockedThread, (void*)tid1); 

    // sleep for 1 sec so that thread 1
    // would get a chance to run first
    sleep(2);

    releaseFun(tid1);
    sleep(2);
    releaseFun(tid2);
    // wait for the completion of thread 2
    pthread_join(tid, NULL);

    return 0;
}

// ===================================================

#include <stdio.h>
#include <stdlib.h>

// #include <iostream>

#include <errno.h>
#include <signal.h>

#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include <pthread.h>
#include <unistd.h>

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


/*
WINDOWS 缺少库函数，得在Linux下运行


*DECRIPTION:    正确到处理信号

*    int pthread_kill(pthread_t thread, int sig);
*        向线程thread发送sig信号，成功返回0，失败返回错误码
*
*    int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
*        为信号signum设置处理函数，处理函数在sigaction中指定
*        act.sa_mask 信号屏蔽字
*        act.sa_handler 信号集处理程序
*
* int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset);
*        多线程信号屏蔽函数
*        how = SIG_BLOCK：向当前的信号掩码中添加set，其中set表示要阻塞的信号组。
*        SIG_UNBLOCK：向当前的信号掩码中删除set，其中set表示要取消阻塞的信号组。
* SIG_SETMASK：将当前的信号掩码替换为set，其中set表示新的信号掩码。
* 在多线程中，新线程的当前信号掩码会继承创造它的线程的信号掩码
*/


void sig_handler1(int arg) {
    printf("thread1 get signal\n");
    return;
}

void sig_handler2(int arg) {
    printf("thread2 get signal\n");
    return;
}

void* thread_fun1(void* arg) {
    printf("new thread 1\n");

    struct sigaction act;

    memset(&act, 0, sizeof(act));
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_handler = sig_handler1;
    sigaction(SIGQUIT, &act, NULL);

    pthread_sigmask(SIG_BLOCK, &act.sa_mask, NULL);
    while(1)
        sleep(2);

    return (void*)0;
}

void* thread_fun2(void* arg) {
    printf("new thread 2\n");

    // WINDOWS 缺少库函数，得在Linux下运行
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_handler = sig_handler2;
    sigaction(SIGQUIT, &act, NULL);

    // pthread_sigmask(SIG_BLOCK, &act.sa_mask, NULL);

    while(1) {
        printf(" - fun2 - \n");
        sleep(2);
    }
}

int main() {
    pthread_t tid1, tid2;
    int err;
    int s;

    err = pthread_create(&tid1, NULL, thread_fun1, NULL);
    if (err != 0) {
        printf("create new thread 1 failed\n");
        return 0;
    }

    err = pthread_create(&tid2, NULL, thread_fun2, NULL);
    if (err != 0) {
        printf("create new thread 2 failed\n");
        return 0;
    }

    sleep(1);
    s = pthread_kill(tid1, SIGQUIT);
    if (s != 0) {
        printf("send signal to thread1 failed\n");
    }

    s = pthread_kill(tid2, SIGQUIT);
    if (s != 0) {
        printf("send signal to thread2 failed\n");
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

// ===============================================

mutex g_mutex[5];

void tfn(void* arg) {
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
        g_mutex[left].lock();
        int ret = g_mutex[right].try_lock();
        if (ret != 0) {
            // 尝试拿右手筷子失败，把左手的筷子释放
            g_mutex[left].unlock();
            cout << "哲学家 " << i << " 没有抢到筷子..." << endl;
            sleep(1);
            continue;
        }
        // 拿到了两支筷子
        // 吃面
        cout << "哲学家 " << i << " 正在吃面..." << endl;
        sleep(1);

        // 吃完面，释放筷子.
        g_mutex[left].unlock();
        g_mutex[right].unlock();
        // sleep(1);
    }
}

int main() {
    thread pth[5];

    // 创建5个线程，相当于5个哲学家
    for (int i = 0; i < 5; i++) {
        pth[i] = thread(tfn, (void*)i);
    }
    // 回收子线程
    for (int i = 0; i < 5; i++) {
        pth[i].join();
    }

    return 0;
}