#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int ticket_sum = 10;
//创建互斥锁
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
//模拟售票员卖票
void *sell_ticket(void *arg) {
    //输出当前执行函数的线程 ID
    printf("当前线程ID：%u\n", pthread_self());
    int i;
    int islock = 0;
    for (i = 0; i < 10; i++)
    {
        //当前线程“加锁”
        islock = pthread_mutex_lock(&myMutex);
        //如果“加锁”成功，执行如下代码
        if (islock == 0) {
            //如果票数 >0 ,开始卖票
            if (ticket_sum > 0)
            {
                sleep(1);
                printf("%u 卖第 %d 张票\n", pthread_self(), 10 - ticket_sum + 1);
                ticket_sum--;
            }
            //当前线程模拟完卖票过程，执行“解锁”操作
            pthread_mutex_unlock(&myMutex);
        }
    }
    return 0;
}
int main() {
    int flag;
    int i;
    void *ans;
    //创建 4 个线程，模拟 4 个售票员
    pthread_t tids[4];
    for (i = 0; i < 4; i++)
    {
        flag = pthread_create(&tids[i], NULL, &sell_ticket, NULL);
        if (flag != 0) {
            printf("线程创建失败!");
            return 0;
        }
    }
    sleep(10);   //等待 4 个线程执行完成
    for (i = 0; i < 4; i++)
    {
        //阻塞主线程，确认 4 个线程执行完成
        flag = pthread_join(tids[i], &ans);
        if (flag != 0) {
            printf("tid=%d 等待失败！", tids[i]);
            return 0;
        }
    }
    return 0;
}