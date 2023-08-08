#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
 
#define MAXSIZE 10
 
int stack[MAXSIZE];
 
int size =0;
sem_t sem;
 
void privide_data(void)
{
  int i;
  for(i =0;i<MAXSIZE;++i)
  {
    stack[i] = i;
    sem_post(&sem);
  }
}
 
void handle_data(void)
{
  int i;
  while((i = size ++) <MAXSIZE)
  {
    sem_wait(&sem);
    printf("cross : %d X %d = %d \n",stack[i],stack[i],stack[i] * stack[i]);
    sleep(1);
  }
}
 
int main()
{
  pthread_t privider,handler;
  sem_init(&sem,0,0);
  pthread_create(&privider,NULL,(void *)&privide_data,NULL);
  pthread_create(&handler,NULL,(void *)&handle_data,NULL);
  pthread_join(privider,NULL);
  pthread_join(handler,NULL);
  sem_destroy(&sem);
 
  return 0;
}