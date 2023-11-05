#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function
void sigint_handler(int signum) {
    if(signo == SIGTERM) {
        printf("Caught signal %d (SIGINT)\n", signum);
        pthread_exit(NULL);
    }
}

void* fun1(void *arg) {
    signal(SIGINT, sigint_handler);
    while(1) {
        printf(" - f1 - Press Ctrl+C to trigger the SIGINT signal...\n");
        sleep(1);
    }
}

void runAPI(void* fun) {
    pthread_t t1;
    pthread_create(&t1, NULL, fun1, NULL);
    // set to detached

    // pthread_join(t1, NULL);
}

void stopAPI() {

}

void api1(void) {
    printf(" - api 1 - \n");
}



int main() {
    // Registering the signal handler for SIGINT (Ctrl+C)


    pthread_t t1 = runAPI(api1);
    stopAPI(api1);

    

    return 0;
}
