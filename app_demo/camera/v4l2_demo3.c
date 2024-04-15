#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/videodev2.h>

#define CAMERA_DEVICE "/dev/video0"

int main() {
    int fd;
    struct v4l2_format fmt;
    struct v4l2_requestbuffers reqbuf;
    struct v4l2_buffer buf;
    void *buffer;

    // 打开摄像头设备
    fd = open(CAMERA_DEVICE, O_RDWR);
    if (fd == -1) {
        perror("Failed to open camera");
        return EXIT_FAILURE;
    }

    // 设置视频格式
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 640;
    fmt.fmt.pix.height = 480;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
    if (ioctl(fd, VIDIOC_S_FMT, &fmt) == -1) {
        perror("Failed to set format");
        close(fd);
        return EXIT_FAILURE;
    }

    // 请求缓冲区
    reqbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    reqbuf.memory = V4L2_MEMORY_MMAP;
    reqbuf.count = 4; // 可以根据需要调整缓冲区的数量
    if (ioctl(fd, VIDIOC_REQBUFS, &reqbuf) == -1) {
        perror("Failed to request buffers");
        close(fd);
        return EXIT_FAILURE;
    }

    // 映射缓冲区
    struct buffer {
        void *start;
        size_t length;
    } *buffers = malloc(reqbuf.count * sizeof(*buffers));

    for (int i = 0; i < reqbuf.count; ++i) {
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;
        if (ioctl(fd, VIDIOC_QUERYBUF, &buf) == -1) {
            perror("Failed to query buffer");
            close(fd);
            return EXIT_FAILURE;
        }
        buffers[i].length = buf.length;
        buffers[i].start = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
        if (buffers[i].start == MAP_FAILED) {
            perror("Failed to map buffer");
            close(fd);
            return EXIT_FAILURE;
        }
    }

    // 将缓冲区入队
    for (int i = 0; i < reqbuf.count; ++i) {
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;
        if (ioctl(fd, VIDIOC_QBUF, &buf) == -1) {
            perror("Failed to enqueue buffer");
            close(fd);
            return EXIT_FAILURE;
        }
    }

    // 开始捕获图像
    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_STREAMON, &type) == -1) {
        perror("Failed to start capturing");
        close(fd);
        return EXIT_FAILURE;
    }

    // 捕获图像
    // 这里可以通过循环不断调用ioctl(VIDIOC_DQBUF)和ioctl(VIDIOC_QBUF)来捕获连续的图像帧
    // 请注意，这里的示例只是捕获了一帧图像
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    if (ioctl(fd, VIDIOC_DQBUF, &buf) == -1) {
        perror("Failed to dequeue buffer");
        close(fd);
        return EXIT_FAILURE;
    }

    // 将图像数据处理为您需要的格式
    // 这里仅打印了图像数据的大小
    printf("Captured image size: %d bytes\n", buf.bytesused);

    // 图像处理完成后，将缓冲区重新入队
    if (ioctl(fd, VIDIOC_QBUF, &buf) == -1) {
        perror("Failed to enqueue buffer");
        close(fd);
        return EXIT_FAILURE;
    }

    // 停止捕获图像
    if (ioctl(fd, VIDIOC_STREAMOFF, &type) == -1) {
        perror("Failed to stop capturing");
        close(fd);
        return EXIT_FAILURE;
    }

    // 关闭摄像头设备
    close(fd);
    return EXIT_SUCCESS;
}
