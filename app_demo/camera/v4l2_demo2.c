#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include <asm/types.h>
#include <linux/videodev2.h>

#define CAMERA_DEVICE "/dev/video0"
#define CAPTURE_FILE "frame.jpg"

#define VIDEO_WIDTH  640
#define VIDEO_HEIGHT 480
#define VIDEO_FORMAT V4L2_PIX_FMT_YUYV
#define BUFFER_COUNT 4

typedef struct VideoBuffer {
    void *start;
    size_t length;
}VideoBuffer;

int fd;             //摄像头文件描述符

void open_camera(char *path);
void get_camera_info();
void get_vedio_info();

//打开设备
void open_camera(char *path) {
    fd = open(CAMERA_DEVICE, O_RDWR, 0);
    if(fd < 0) {
        printf("Open %s failed\n", CAMERA_DEVICE);
        exit(EXIT_FAILURE);
    }
}

//获取驱动信息
void get_camera_info() {
    struct v4l2_capability cap;
    int ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
    if(ret < 0) {
        printf("VIDIOC_QUERYCAP failed (%d)\n", ret);
        return ret;
    }
    // Print capability informations
    printf("Capbility Informations:\n");
    printf("*\tdriver: %s\n", cap.driver);
    printf("*\tcard: %s\n", cap.card);
    printf("*\tbus_info: %s\n", cap.bus_info);
    printf("*\tversion: %08X\n", cap.version);
    printf("*\tcapabilities: %08X\n", cap.capabilities);
}

//获取视频格式
void get_vedio_info() {
    struct v4l2_format fmt;
    memset(&fmt, 0, sizeof(fmt));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    int ret = ioctl(fd, VIDIOC_G_FMT, &fmt);
    if(ret < 0) {
        printf("VIDIOC_G_FMT failed (%d)\n", ret);
        return ret;
    }
    // Print Stream Format
    printf("Stream Format Informations:\n");
    printf("*\ttype: %d\n", fmt.type);
    printf("*\twidth: %d\n", fmt.fmt.pix.width);
    printf("*\theight: %d\n", fmt.fmt.pix.height);

    char fmtstr[8];
    memset(fmtstr, 0, 8);
    memcpy(fmtstr, &fmt.fmt.pix.pixelformat, 4);
    printf("*\tpixelformat: %s\n", fmtstr);
    printf("*\tfield: %d\n", fmt.fmt.pix.field);
    printf("*\tbytesperline: %d\n", fmt.fmt.pix.bytesperline);
    printf("*\tsizeimage: %d\n", fmt.fmt.pix.sizeimage);
    printf("*\tcolorspace: %d\n", fmt.fmt.pix.colorspace);
    printf("*\tpriv: %d\n", fmt.fmt.pix.priv);
    //    printf("*\traw_data: %s\n", fmt.fmt.raw_data);

    /* 显示所有支持的格式 */
    struct v4l2_fmtdesc fmtdesc;
    fmtdesc.index = 0;
    fmtdesc.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    printf("Support format:\n");
    while(ioctl(fd, VIDIOC_ENUM_FMT, &fmtdesc) != -1) {
        printf("\t%d.%s\n", fmtdesc.index+1, fmtdesc.description);
        fmtdesc.index++;
    }
}

int main() {
    int i, ret;
    open_camera(CAMERA_DEVICE);

    get_camera_info();

    get_vedio_info();

    //请求分配内存
    struct v4l2_requestbuffers reqbuf;
    reqbuf.count = BUFFER_COUNT;
    reqbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    reqbuf.memory = V4L2_MEMORY_MMAP;
    ret = ioctl(fd, VIDIOC_REQBUFS, &reqbuf);
    if(ret < 0) {
        printf("VIDIOC_REQBUFS failed (%d)\n", ret);
        return ret;
    }
    //获取空间
    VideoBuffer *buffers = calloc(reqbuf.count, sizeof(*buffers));
    if(!buffers) {
        //映射
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<reqbuf.count;i++) {
        struct v4l2_buffer buf;
        memset(&buf, 0, sizeof(buf));
        buf.index = i;
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        ret = ioctl(fd, VIDIOC_QUERYBUF, &buf);
        if(ret < 0) {
            printf("VIDIOC_QUERYBUF (%d) failed (%d)\n", i, ret);
            return ret;
        }
        // mmap buffer
        buffers[i].length = buf.length;
        buffers[i].start = (char *)mmap(0, buf.length, PROT_READ|PROT_WRITE, MAP_SHARED,
            fd, buf.m.offset);
        if(buffers[i].start == MAP_FAILED) {
            printf("mmap (%d) failed: %s\n", i, strerror(errno));
            return -1;
        }

        // Queen buffer
        ret = ioctl(fd, VIDIOC_QBUF, &buf);
        if(ret < 0) {
            printf("VIDIOC_QBUF (%d) failed (%d)\n", i, ret);
            return -1;
        }

        printf("Frame buffer: %d: address=0x%x, length=%d\n", i,
            (unsigned int)buffers[i].start, buffers[i].length);
    }

    // 开始录制
    struct v4l2_buffer buf;
    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.index = 0;
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    ret = ioctl(fd, VIDIOC_STREAMON, &type);
    if (ret < 0) {
        printf("VIDIOC_STREAMON failed (%d)\n", ret);
        return ret;
    }

    // Get frame
    ret = ioctl(fd, VIDIOC_DQBUF, &buf);
    if (ret < 0) {
        printf("VIDIOC_DQBUF failed (%d)\n", ret);
        return ret;
    }

    // Process the frame
    FILE *fp = fopen(CAPTURE_FILE, "wb");
    if (fp < 0) {
        printf("open frame data file failed\n");
        return -1;
    }
    fwrite(buffers[buf.index].start, 1, buf.length, fp);
    fclose(fp);
    printf("Capture one frame saved in %s\n", CAPTURE_FILE);

    // Re-queen buffer
    ret = ioctl(fd, VIDIOC_QBUF, &buf);
    if (ret < 0) {
        printf("VIDIOC_QBUF failed (%d)\n", ret);
        return ret;
    }

    // Release the resource
    for(i=0;i<4;i++) {
        munmap(buffers[i].start, buffers[i].length);
    }

    close(fd);
    printf("Camera test Done.\n");
    return 0;
}