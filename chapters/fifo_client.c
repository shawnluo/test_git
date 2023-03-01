#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIFO_SERVER "./myfifo"

int main(void) {
    char buf_write[100];
    int fd;
    int nwrite;

    fd = open(FIFO_SERVER, O_WRONLY | O_NONBLOCK, 0);
    if(fd == -1) {
        perror("open");
        exit(1);
    }

    strcpy(buf_write, "show me the money!");

    if((nwrite = write(fd, buf_write, 100)) == -1) {
        if(errno == EAGAIN) {
            printf("no data yet\n");
        }
    }
    printf("write %s to the FIFO\n", buf_write);

    return 0;
}