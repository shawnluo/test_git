#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/prctl.h>

typedef void (*pF)();

// Signal handler function
void sigint_handler(int signum) {

    printf("signum: %d\n", signum);
    if(signum == SIGINT) {
        printf("Caught signal %d (SIGINT)\n", signum);
        // pthread_exit(NULL);
        exit(1);
    }
}

void *fun1() {
    signal(SIGINT, sigint_handler);
    while(1) {
        printf(" - f1 - Press Ctrl+C to trigger the SIGINT signal...\n");
        sleep(1);
    }
}

pthread_t runAPI(void* fun) {
    pthread_t t;
    pthread_create(&t, NULL, (pF)(fun), NULL);
    
    pthread_detach(t);  // set to detached
    prctl(PR_SET_NAME, t, 0, 0, 0);

    // pthread_join(t, NULL);  // 在这里等待线程结束，或者在main()中while(1)等待

    printf(" - detached - \n");

    return t;
}

void stopAPI(pF fun) {

}


void showMe() {
    printf("hello\n");
}

void run(void* fun) {
    ((pF)(fun))();
}


int main() {
    pthread_t t1 = runAPI(fun1);
    // stopAPI(fun1);

    // run(showMe);

    while(1) {
        sleep(1);
    }

    return 0;
}
