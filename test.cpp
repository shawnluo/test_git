


#include "test.hpp"
#include <thread>

using namespace std;

/* TODO
    1. 🔥   find island
    2. 🔥   decimal to bin c/c++
    3. bin to decimal c/c++
    4. blur
    5. memcpy
    6. memcpy align
    7. delete extra spaces in a string
    8. robbing houses
    9. rangeBitwiseAnd
 */

int partition(vector<int> nums, int start, int end) {
    int pivot = nums[end];
    int j = start - 1;
    for(int i = start; i < end; i++) {
        if(nums[i] < pivot) {
            swap(nums[++j], nums[i]);
        }
    }
    swap(nums[++j], nums[end]);
    return j;
}

void quickSort(vector<int>& nums, int start, int end) {
    if(start > end) {
        return;
    }
    int pivot = partition(nums, start, end);
    quickSort(nums, start, pivot - 1);
    quickSort(nums, pivot + 1, end);
}

pthread_mutex_t mutex;
sem_t full;
sem_t empty;

void* producer(void* arg) {
    int item = 0;
    while(1) {
        pthread_testcancel();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

int main(void) {
    pthread_t pth[3];
    for(long i = 0; i < 3; i++) {
        pthread_create(&pth[i], nullptr, producer, (void*)i);
    }

    for(long i = 0; i < 3; i++) {
        pthread_join(pth[i], nullptr);
    }

    return 0;
}