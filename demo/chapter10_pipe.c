#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include <sys/mman.h> //mmap函数的必要头文件
#include <sys/stat.h> // struct stat 需要的头文件
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include "test.h"

int main(void) {
    int pipe_fd[2];
    pid_t pid;
    char buf_read[100];
    int num_read;
    memset(buf_read, 0, sizeof(buf_read));

    if(pipe(pipe_fd) < 0) {
        printf("pipe create error\n");
        return -1;
    }

    if((pid = fork()) == 0) { //child process
        printf("\n");
        close(pipe_fd[1]);
        sleep(2);

        if((num_read = read(pipe_fd[0], buf_read, 100)) > 0) {
            printf("%d  %s\n", num_read, buf_read);
        }

        close(pipe_fd[0]);
        exit(0);
    } else if(pid > 0) {
        close(pipe_fd[0]);
        if(write(pipe_fd[1], "Hello", 5) != -1) {
            printf("parent write 1 success!\n");
        }
        if(write(pipe_fd[1], " Pipe", 5)) {
            printf("parent write 2 success!\n");
        }
        close(pipe_fd[1]);
        sleep(3);
        waitpid(pid, NULL, 0);
        exit(0);
    }
}