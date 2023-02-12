
#include <stdio.h>
#include <sys/mman.h> //mmap函数的必要头文件
#include <sys/stat.h> // struct stat 需要的头文件
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#pragma once
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#define ARGS_CHECK(argc,num) {if(argc!=num)\
    {fprintf(stderr,"args error!\n");return -1;}}
#define ERROR_CHECK(ret,num,msg) {if(ret==num)\
    {perror(msg);return -1;}}



int dataType(void) {
    printf( "Size of C data types:\n\n"                                 );
    printf( "Type               Bytes\n\n"                             );
    printf( "--------------------------------\n");
    printf( "char                 %lu\n" , sizeof( char )               );
    printf( "int8_t               %lu\n" , sizeof( int8_t )             );
    printf( "unsigned char        %lu\n" , sizeof( unsigned char )      );
    printf( "uint8_t              %lu\n" , sizeof( uint8_t )            );
    printf( "short                %lu\n" , sizeof( short )              );
    printf( "int16_t              %lu\n" , sizeof( int16_t )            );
    printf( "uint16t              %lu\n" , sizeof( uint16_t )           );
    printf( "int                  %lu\n" , sizeof( int )                );
    printf( "unsigned             %lu\n" , sizeof( unsigned )           );
    printf( "long                 %lu\n" , sizeof( long )               );
    printf( "unsigned long        %lu\n" , sizeof( unsigned long )      );
    printf( "int32_t              %lu\n" , sizeof( int32_t )            );
    printf( "uint32_t             %lu\n" , sizeof( uint32_t )           );
    printf( "long long            %lu\n" , sizeof( long long )          );
    printf( "int64_t              %lu\n" , sizeof( int64_t )            );
    printf( "unsigned long long   %lu\n" , sizeof( unsigned long long ) );
    printf( "uint64_t             %lu\n" , sizeof( uint64_t )           );
    printf( "float                %lu\n" , sizeof( float )              );
    printf( "double               %lu\n" , sizeof( double )             );
    printf( "long double          %lu\n" , sizeof( long double )        );
    printf( "_Bool                %lu\n" , sizeof( _Bool )              );
    printf( "\n" );
    return 0;
}


 
int main(int argc,char *argv[]) {
    ARGS_CHECK(argc, 2);//检查命令行参数
    int fd = open(argv[1], O_RDWR);//以读写的方式把文件从磁盘读入内核缓冲区，返回文件描述符
    ERROR_CHECK(fd, -1, "open");//检查是否成功打开文件
    int ret = ftruncate(fd, 5);//文件大小限定在5B
    char *p = (char *)mmap(NULL, 5, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    puts(p);    //p指向mmap映射出来的堆上内存
    p[0] = 'H'; //由于磁盘与内存已建立映射关系，所以内存被修改对应的磁盘内容也被修改
    p[1] = 'x';
    p[2] = 'x';
    p[3] = 'x';
    p[4] = 'x';

    fprintf((char *)p, "%s", "gogogo");
    puts(p);
    munmap(p, 5);//解除映射并释放mmap申请的堆空间
    close(fd);//断开文件描述符指向，释放内核缓冲区
    return 0;
}