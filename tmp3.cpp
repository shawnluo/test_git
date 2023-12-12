#include <pthread.h>
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

typedef struct thread_info {
    pthread_t thread_id;
    int thread_argNum;
    unsigned int delay;
    string message;
} TI;   // thread info

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int condCount = 0;
int NUMS = 0;

void* producer(void* arg) {
    TI* info = (TI*)arg;

    for (;;) {
        pthread_mutex_lock(&mutex);

        while (condCount != info->thread_argNum) {
            pthread_cond_wait(&cond, &mutex);
        }

        for (int i = 0; i < 5; i++) {
            cout << " - in producer - " << info->message << " produce: " << i << endl;
        }

        sleep(info->delay);
        condCount = (condCount + 1) % NUMS;

        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }

    pthread_exit(NULL);
}

int main(void) {
    vector<TI> tRunner;

    TI myThreadInfo;

    myThreadInfo.thread_argNum = 0;
    myThreadInfo.delay = 2;
    myThreadInfo.message = "Alice";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 1;
    myThreadInfo.delay = 1;
    myThreadInfo.message = "Bob";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 2;
    myThreadInfo.delay = 2;
    myThreadInfo.message = "Charli";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 3;
    myThreadInfo.delay = 3;
    myThreadInfo.message = "David";
    tRunner.push_back(myThreadInfo);

    myThreadInfo.thread_argNum = 4;
    myThreadInfo.delay = 4;
    myThreadInfo.message = "Eva";
    tRunner.push_back(myThreadInfo);

    NUMS = tRunner.size();
    cout << NUMS << endl;

    for (size_t i = 0; i < NUMS; i++) {
        pthread_create(&tRunner[i].thread_id, NULL, producer, &tRunner[i]);
    }

    sleep(5);
    for (size_t i = 0; i < NUMS; i++) {
        cout << " - main - cancel: " << tRunner[i].thread_argNum << endl;
        pthread_cancel(tRunner[i].thread_id);
    }

    for (size_t i = 0; i < NUMS; i++) {
        pthread_join(tRunner[i].thread_id, NULL);
    }

    return 0;
}
