/*fifo_write.c*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#define FIFO "/tmp/myfifo"

int main(int argc, char** argv)
/*参数为即将写入的字节数*/
{
    int fd;
    char w_buf[100];
    int nwrite;
    if (fd == -1)
        if (errno == ENXIO) printf("open error; no reading process\n");
    /*打开 FIFO 管道，并设置非阻塞标志*/
    fd = open(FIFO_SERVER, O_WRONLY | O_NONBLOCK, 0);
    if (argc == 1) printf("Please send something\n");

    strcpy(w_buf, argv[1]);
    /*向管道中写入字符串*/
    if ((nwrite = write(fd, w_buf, 100)) == -1) {
        if (errno == EAGAIN) printf("The FIFO has not been read yet.Please try later\n");
    } else
        printf("write %s to the FIFO\n", w_buf);
}



/*fifl_read.c*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#define FIFO "/tmp/myfifo"

int main(int argc, char** argv) {
    char buf_r[100];
    int fd;
    int nread;
    /*创建有名管道，并设置相应的权限*
    if((mkfifo(FIFO,O_CREAT|O_EXCL)<0)&&(errno!=EEXIST))
    printf("cannot create fifoserver\n");
    printf("Preparing for reading bytes...\n");
    memset(buf_r,0,sizeof(buf_r));
    /*打开有名管道，并设置非阻塞标志*/
    fd = open(FIFO, O_RDONLY | O_NONBLOCK, 0);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    while (1) {
        memset(buf_r, 0, sizeof(buf_r));
        if ((nread = read(fd, buf_r, 100)) == -1) {
            if (errno == EAGAIN) printf("no data yet\n");
        }
        printf("read %s from FIFO\n", buf_r);
        sleep(1);
    }
    pause();
    unlink(FIFO);
}