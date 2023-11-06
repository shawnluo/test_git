
// --------------------------- 向特定thread 发送signal -------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>

/*DATE:            2015-3-31
 *AUTHOR:        WJ
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

    // pthread_sigmask(SIG_BLOCK, &act.sa_mask, NULL);
    sleep(2);
}

void* thread_fun2(void* arg) {
    printf("new thread 2\n");

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_handler = sig_handler2;
    sigaction(SIGQUIT, &act, NULL);

    // pthread_sigmask(SIG_BLOCK, &act.sa_mask, NULL);
    sleep(2);
}

int main() {
    pthread_t tid1, tid2;
    int err;
    int s;

    err = pthread_create(&tid1, NULL, thread_fun1, NULL);
    if (err != 0) {
        printf("create new thread 1 failed\n");
        return;
    }
    err = pthread_create(&tid2, NULL, thread_fun2, NULL);
    if (err != 0) {
        printf("create new thread 2 failed\n");
        return;
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
