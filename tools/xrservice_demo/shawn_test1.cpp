/* #include <iostream>
#include <thread>
#include <vector>

void threadFunction(int thread_id) {
    std::cout << "Thread " << thread_id << " is running.\n";
}

int main() {
    const int num_threads = 4;
    std::vector<std::thread> threads;

    // Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(threadFunction, i));
    }

    // Join the threads with the main thread
    for (auto& th : threads) {
        th.join();
    }

    std::cout << "All threads finished.\n";
    return 0;
}
 */

#include <thread>
#include <iostream>

void threadFunction(int value) {
    std::cout << "Thread is running with value: " << value << "\n";
}

int main() {
    int x = 10;
    std::thread t(threadFunction, x);  // 将 x 传递给 threadFunction
    t.join();  // 等待线程完成
    std::cout << "Thread finished\n";
    return 0;
}