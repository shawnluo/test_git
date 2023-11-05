#include "common.h"
#include "test.h"

#include <stdio.h>
#include <stdlib.h>

#define _MAX_X 5 // 迷宫的大小
#define _MAX_Y 4


int main(void) {
    int fd[2];
    if(pipe(fd) == -1) {
        printf("An error\n");
        return 1;
    }

    int id = fork();

    if(id == 0) { // 子进程
        printf("child_id: %d\n", getpid());

        close(fd[0]);

        int x;
        printf("Input a number: ");
        scanf("%d", &x);

        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    } else { // 父进程
        close(fd[1]);

        int y;
        read(fd[0], &y, sizeof(int));
        printf("%d\n", y);

        close(fd[0]);
    }


    return 0;
}