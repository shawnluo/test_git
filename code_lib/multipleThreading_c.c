#include "test.hpp"

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


sem_t g_semt;

void* work_thread(void* p) {
    // pthread_t tID = pthread_self();
    // cout << "-------" << tID << " is waiting for a semaphore -------" << endl;

    cout << "-------"  << (long)p << " is waiting for a semaphore -------" << endl;
    sem_wait(&g_semt);
    cout << "-------"  << (long)p << " got a semaphore, is Runing -------" << endl << endl;
    usleep(1000 * 1000 * 2); // 2 seconds

    cout << "-------"  << (long)p << " is exiting -------" << endl << endl;
    sem_post(&g_semt);

    // static char* pRet = "thread finished! \n";
    // return pRet;

    return p;
}

int main() {
    const size_t nThreadCount          = 5; // amounts of thread array
    const unsigned int nSemaphoreCount = 3; // initial value of semaphore 在此代码中，决定初始时，有多少个线程可以被同时进入sem_wait。设置成3，则会有3个线程进入sem_wait后的代码
                                            // - 每运行一次sem_wait，其值就会被减少一次。当sem value变成0时，sem_wait则会被阻塞。
                                            // - sem value 不会被变成负数

    int nRet                           = -1;
    void* pRet                         = NULL;
    pthread_t threadIDs[nThreadCount]  = { 0 };

    nRet = sem_init(&g_semt, 0, nSemaphoreCount);
    if (0 != nRet) return -1;

    for (size_t i = 0; i < nThreadCount; ++i) {
        nRet = pthread_create(&threadIDs[i], NULL, work_thread, (void*)i);
        if (0 != nRet) continue;
    }

    for (size_t i = 0; i < nThreadCount; ++i) {
        // long nRet2 = (long)pthread_join(threadIDs[i], &pRet);
        // cout << endl << threadIDs[i] << " return value is " << (char*)pRet << endl;

        pthread_join(threadIDs[i], &pRet);
        cout << endl << threadIDs[i] << " return value is " << (long)pRet << endl;
    }

    cout << endl << endl;

    sem_destroy(&g_semt);

    return 0;
}