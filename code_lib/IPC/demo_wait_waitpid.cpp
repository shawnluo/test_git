
// 该测试代码：测试wait函数返回值，测试wait回收僵尸进程；

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    if (fork() == 0) {
        // child process
        printf("i am a child pid=%d\n", getpid());
        exit(0); // 让子进程退出
    }
    // parent process执行，这里不会执行子进程了，因为子进程被我退出了
    sleep(2); // 休息2s,为的是观察监控消息，是否子进程成为僵尸进程
    printf("wait函数开始执行\n");
    pid_t ret = wait(NULL);
    if (ret == -1) {
        perror("wait error\n");
    }
    // wait返回成功
    printf("wait返回的是子进程的ret=%d执行结束，注意观察监控窗口是否>僵尸进程被回收\n", ret);
    sleep(2); // 不让父进程那么快退出，观察窗口僵尸进程是否被回收
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // child
        printf("i am a process my pid  = %d\n", getpid());
        exit(11); // 退出子进程，我们在父进程调用waitpid来获得子进程的退出码信息
    }
    // parent process
    int status; // 该变量是父进程的变量，为的是在父进程获得子进程的退出状态的信息
    pid_t ret = waitpid(pid, &status, 0); // 传入status的地址，获得子进程的退出的信息
    if (ret == -1) {
        perror("wait failed\n");
    }
    // waitpid 等待成功
    // 打印子进程的stauts退出码信息和终止信号信息，这是在父进获取到子进程的信息
    printf("waitpid 返回的stauts 的退出码信息：%d,终止信号的信息：%d\n", (status >> 8) & 0xFF, status & 0x7F);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // child
        printf("i am a process my pid  = %d\n", getpid());
        exit(11); // 退出子进程，我们在父进程调用waitpid来获得子进程的退出码信息
    }
    // parent process
    int status; // 该变量是父进程的变量，为的是在父进程获得子进程的退出状态的信息
    pid_t ret = waitpid(pid, &status, 0); // 传入status的地址，获得子进程的退出的信息
    if (ret == -1) {
        perror("wait failed\n");
    }
    // waitpid 等待成功
    if (WIFEXITED(status)) {
        printf("子进程pid = %d 正常退出，父进程获得子进程的退出码为：%d\n", pid, WEXITSTATUS(status));
    } else {
        printf("WIFEXITED为假，子进程异常退出，非正常退出\n");
    }
    return 0;
}
