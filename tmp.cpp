
#include "test.hpp"


mutex g_mutex[5];

void tfn(void* arg) {
    int i = (long)arg;
    int left, right;
    if (i == 4) {
        // 防止震荡现象发生。
        left  = 0;
        right = i;
    } else {
        left  = i;
        right = i + 1;
    }
    while (1) {
        g_mutex[left].lock();
        int ret = g_mutex[right].try_lock();
        if (ret != 0) {
            // 尝试拿右手筷子失败，把左手的筷子释放
            g_mutex[left].unlock();
            cout << "哲学家 " << i << " 没有抢到筷子..." << endl;
            sleep(1);
            continue;
        }
        // 拿到了两支筷子
        // 吃面
        cout << "哲学家 " << i << " 正在吃面..." << endl;
        sleep(1);

        // 吃完面，释放筷子.
        g_mutex[left].unlock();
        g_mutex[right].unlock();
        // sleep(1);
    }
}

int main() {
    thread pth[5];

    // 创建5个线程，相当于5个哲学家
    for (int i = 0; i < 5; i++) {
        pth[i] = thread(tfn, (void*)i);
    }
    // 回收子线程
    for (int i = 0; i < 5; i++) {
        pth[i].join();
    }

    return 0;
}