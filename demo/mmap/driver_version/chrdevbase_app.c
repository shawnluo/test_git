#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
 
char readbuf[100];
char writebuf[100] = "Hello Kernel\n";
 
int main() {
    setvbuf(stdout, (char *)NULL, _IONBF, 0);
    int fd = open("/dev/chrdevbase", O_RDWR);
    assert(fd >= 0);
 
    int ret;
 
    ret = read(fd, readbuf, sizeof(readbuf));
    assert(ret >= 0);
    fflush(stdout);
    printf("read %d : %s", ret, readbuf);
    fflush(stdout);
    sleep(5);
    ret = write(fd, writebuf, sizeof(writebuf));
    assert(ret >= 0);
 
    ret = close(fd);
    assert(ret >= 0);
}