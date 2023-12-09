#include "test.hpp"

void* producer(void* arg) {
    for(;;) {
        pthread_testcancel();

        cout << " - in producer - " << *(int*)arg << endl;
        sleep(2);
        // pthread_exit(NULL);
    }
}

int main(void) {
    int NUM = 5;
    pthread_t tid[NUM];
    for(int i = 0; i < NUM; i++) {
        // cout << *(int*)&i << endl;
        // pthread_create(&tid[i], NULL, producer, (void*)&i);
    }

    int tid0 = 0;
    int tid1 = 1;
    int tid2 = 2;
    int tid3 = 3;
    int tid4 = 4;
    
    vector<pair<string, int>> v;
    v.push_back({"show", 10});

    if(find_if(v.begin(), v.end(), [&](const ))) {

    }
    cout << 
    
    
    pthread_create(&tid[0], NULL, producer, (void*)&tid0);
    pthread_create(&tid[1], NULL, producer, (void*)&tid1);
    pthread_create(&tid[2], NULL, producer, (void*)&tid2);
    pthread_create(&tid[3], NULL, producer, (void*)&tid3);
    pthread_create(&tid[4], NULL, producer, (void*)&tid4);
    cout << " - in main - " << endl;

    sleep(5);
    for(int i = 0; i < NUM; i++) {
        // pthread_cancel(tid[i]);
    }

    for(int i = 0; i < NUM; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}