// fifo_r.c

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

typedef struct SensorReading {
    int status;
    float lux;
    int timestamp;
} SR;


int top = 0;

SR data[10000];


void* readSensor(void*) {
    time_t t;
    srand((unsigned) time(&t));
    for (;;) {
        pthread_testcancel();
        data[top].lux = (rand() % 50) * 1.0; // = read_next_sample();
        // float dataLux = data[top].lux;
        // top++;
        sleep(1);
    }
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, readSensor, NULL);
    // data[0]

    sleep(1);


    while (1) {
        printf("%f\n", data[0].lux);
        sleep(1);
    }

    pthread_cancel(tid);
    pthread_join(tid, NULL);
    return 0;
}