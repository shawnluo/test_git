
#include "test.hpp"

sem_t emptyBuffer;
sem_t fullBuffer;
mutex g_mutex;
queue<int> buffer; // 全局变量

/*
    1. sem_init 初始值的意义？
        可以初始化 n 个生产者，或者 n 个消费者。相应建立 n 个进程

    2. g_mutex.lock() 存在的意义？
        防止 producer() 和 customer() 被被多个线程同时访问。

    3. 两个semaphore 同时存在的意义？
        分别是 生产者 sem 和 消费者 sem。用于同步两个线程：消费者执行完之后，再执行生产者；生产者执行完之后，再执行消费者。

    4. sem 和 lock 一起联合使用的目的？
        通过上述问题，答案显而易见：
            1）. lock: 同一个线程如果执行同一个函数，用lock来保证同一时刻，只有一个线程进入执行。
            2）. sem:  保证生产者和消费者线程的执行顺序，也就是synchnization.
 */


void blur(const vector<vector<int>>& mat, vector<vector<int>>& newMat, int size) {
    if(size <= 1) {return;}

    int padding  = size / 2;
    int n = mat.size();
    int newN = n + padding * 2;
    // cout << padding << endl;
    // cout << n << " " << newN << endl;
    vector<vector<int>> matPadding(newN, vector<int>(newN, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // matPadding[i + padding][j + padding] = mat[i][j];
        }
    }

    int startX = 0;
    int startY = 0;
    int offset = 1;
    int count = 1;
    int half = newN / 2;
    while(half--) {
        int x = startX;
        int y = startY;
        for(; y < newN - offset; y++) {
            matPadding[x][y] = count++;
        }
        for(; x < newN - offset; x++) {
            matPadding[x][y] = count++;
        }
        for(; y > startY; y--) {
            matPadding[x][y] = count++;
        }
        for(; x > startX; x--) {
            matPadding[x][y] = count++;
        }

        startX++;
        startY++;
        offset++;
    }

    // for_each(matPadding.begin(), matPadding.end(), [](auto x){
    //     for_each(x.begin(), x.end(), [](auto y){cout << y << "\t" << " ";});
    //     cout << endl;
    // });
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matPadding[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = { {1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15},
                                {16, 17, 18, 19, 20},
                                {21, 22, 23, 24, 25}};
    
    vector<vector<int>> newMat(mat.size(), vector<int>(mat.size(), 0));

    int size = 3;
    vector<vector<int>> core = {{1, 0, -1},
                                {-1, 0, 1},
                                {0, 1, -1}};

    blur(mat, newMat, size);

    // for_each(mat.begin(), mat.end(), [](auto x){
    //     for_each(x.begin(), x.end(), [](auto y){cout << y << " ";});
    //     cout << endl;
    // });
    return 0;
}