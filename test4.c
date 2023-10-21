#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdio.h>  
#include<stdlib.h>  
#include <sys/ipc.h>
#include <sys/sem.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <sys/ipc.h>
       #include <sys/sem.h>
       #include <unistd.h>

int main(int argc, char **argv) {
	int sem_id = semget(12);

	// 第一次调用多加一个参数，第二次调用不加参数，仅在第一次调用时创建信号量
	if (argc > 1 && (!set_sem(sem_id))) {
		printf("set sem failed.\n");
		return -1;
	}

	// P 操作
	sem_down(sem_id);
	printf("sem lock...\n");

	printf("do something...\n");
	sleep(10);

	// V 操作
	sem_up(sem_id);
	printf("sem unlock...\n");

	// 第二次调用后删除信号量
	if (argc == 1)
		del_sem(sem_id);

	return 0;
}