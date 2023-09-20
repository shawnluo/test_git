
# 搞清楚这些概念以及相关的函数api

# 1. 进程间通信

1. ## pipe

   只能在父子进程中。

   `pipe(pipe_fd)`

   `close(pipe_fd[0])`

   `close(pipe_fd[1])`

   [code](./demo_pipe.cpp)
2. ## popen

   将pipe上述过程**合并**到一个函数popen 中完成。它所完成的工作有以下几步。


   1. 创建一个管道。
   2. fork一个子进程。
   3. 在父子进程中关闭不需要的文件描述符。
   4. 执行 exec 函数族调用。
   5. 执行函数中所指定的命令。
3. ## fifo

   `int mkfifo(const char *filename,mode_t mode)`

   `fd=open(FIFO_SERVER,O_WRONLY|O_NONBLOCK,0)`

   `write(fd,w_buf,100))`

   `read(fd,buf_r,100))`

   [code](demo_fifp.cpp)
4. ## signals

   [code](demo_signal.cpp)

   为避免子进程成为僵尸进程，父进程需要调用waitpid()
5. ## wait/waitpid

    假设**子进程没有合理的回收** ，可能会带来两个问题：

   1. 孤儿进程（父进程挂了，子进程活着），孤儿进程会被**init进程**回收，可以理解其没有危害，不会占用资源。

   2. 僵尸进程（子进程挂了，父进程活着），僵尸进程是当父进程活着时，子进程没有其他进程帮忙回收后产生的“有害进程”，所以僵尸必须要回收，否则僵尸进程太多了会占用系统资源。此时就需要用到wait或waitpid函数。

    **wait和waitpid的区别在于**：

    1.**wait函数是阻塞的**，必须等到子进程被回收才会执行wait之后的代码；

    2.**waitpid可以设置为非阻塞的**，不过非阻塞可能带来新的问题，子进程还没有回收waitpid这句代码就走完了（一般会写循环，通过判断返回值解决）。

code

# 2. 线程间通信

# 3. 共享资源

# 4. 同步与互斥

`sem_wait()`

`sem_post()`

`sem_getvalue()`
