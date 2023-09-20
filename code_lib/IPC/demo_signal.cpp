/*kill.c*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
    下面这个示例首先使用fork创建了一个子进程，接着为了保证子进程不在父进程调用kill
    之前退出，在子进程中使用 raise 函数向子进程发送 SIGSTOP 信号，使子进程暂停。接下来
    再在父进程中调用 kill 向子进程发送信号，在该示例中使用的是 SIGKILL，读者可以使用其
    他信号进行练习。
*/
int main() {
    pid_t pid;
    int ret;
    /*创建一子进程*/
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        /*在子进程中使用 raise 函数发出 SIGSTOP 信号*/
        raise(SIGSTOP);
        exit(0);
    } else {
        /*在父进程中收集子进程发出的信号，并调用 kill 函数进行相应的操作*/
        printf("pid=%d\n", pid);
        if ((waitpid(pid, NULL, WNOHANG)) == 0) {
            if ((ret = kill(pid, SIGKILL)) == 0)
                printf("kill %d\n", pid);
            else {
                perror("kill");
            }
        }
    }
}