#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIFO "./myfifo"

int main(void) {
    char buf_read[100];
    int fd;
    int nread;
    if((mkfifo(FIFO, O_CREAT | O_EXCL) < 0) && (errno != EEXIST)) {
        printf("cannot create fifoserver\n");
    }
    printf("Preparing for reading bytes...\n");
    memset(buf_read, 0, sizeof(buf_read));

    fd = open(FIFO, O_RDONLY | O_NONBLOCK, 0);
    if(fd == -1) {
        perror("open");
        exit(1);
    }

    while(1) {
        memset(buf_read, 0, sizeof(buf_read));
        if((nread = read(fd, buf_read, 100)) == -1) {
            if(errno == EAGAIN) {
                printf("no data yet\n");
            }
        }
        printf("read %s from FIFO\n", buf_read);
        sleep(1);
    }
    pause();
    unlink(FIFO);
}