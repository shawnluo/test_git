


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

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[end];
    int j = start - 1;  // point to the last number which smaller than pivot
    for(int i = start; i < end; i++) {
        if(nums[i] < pivot) {
            // j++;
            if(nums[++j] < pivot) {
                swap(nums[j], nums[i]);
            }
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

class Robot {
public:
    Robot();
    bool move();
    void turnRight();
    void clean();
};

bool Robot::move() {
    // ...
    return false;
}

void dfs(Robot& robot, set<pair<int, int>>& visited, int i, int j, int dir) {
    robot.clean();
    visited.insert(i, j);

    vector<pair<int, int>> directions = {
        {-1,  0},
        { 0,  1},
        { 1,  0},
        { 0, -1},
    };

    for(int k = 0; k < 4; k++) {
        int new_i = i + directions[dir].first;
        int new_j = j + directions[dir].second;

        if(robot.move() && visited.count({new_i, new_j}) == 0) {    // has never visited
            dfs(robot, visited, new_i, new_j, dir);
            robot.turnRight();
            robot.turnRight();
            robot.move();
            robot.turnRight();
            robot.turnRight();
        }

        dir = (dir + 1) % 4;
        robot.turnRight();
    }
}

void cleanRoom(Robot& robot) {
    set<pair<int, int>> visited;

    // visited, i, j, dir
    dfs(robot, visited, 0, 0, 0);
}

int lenOfMin(vector<int> v, int target) {
    // src -------
    //      dst -------
    // dst -------
    //       src -------
    int len = 0;
    int res = INT_MAX;
    int n = v.size();
    int j = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        while(sum >= target) {
            len = i - j + 1;
            res = min(res, len);
            sum -= v[j];
            j++;
        }
    }
    return res == INT_MAX ? 0 : res;
}

void reverse(string& s, int start, int end) {
    if(!s.size()) return;
    int n = s.size();
    int lhs = start;
    int rhs = end;

    while(lhs < rhs) {
        swap(s[lhs++], s[rhs--]);
    }
}

//TODO blur

int removeExtraSpaces(string& s) {
    int lhs = 0;
    int n = s.size();
    for(int rhs = 0; rhs < n; rhs++) {
        if(s[rhs] != ' ') {
            if(lhs != 0) {
                s[lhs++] = ' ';
            }
            
            while(rhs < n && s[rhs] != ' ') {
                s[lhs++] = s[rhs++];
            }
        }
    }
    s.resize(lhs);
    return lhs;
}

void reverse_word(string& s) {
    int n = removeExtraSpaces(s);
    if(n <= 1) return;
    reverse(s, 0, n - 1);

    int lhs = 0;
    int rhs = 0;
    for(int i = 0; i < n; i++) {
         if(s[i] == ' ') {
            reverse(s, lhs, i - 1);
            lhs = i + 1;
         }
    }
}

pNode reverse(pNode pHead) {
    pNode pCur = pHead;
    pNode pPre = nullptr;
    pNode pNex = nullptr;

    while(pCur) {
        pNex = pCur->next;
        pPre = pCur;
        pCur = pNex;
    }
    return pPre;
}

pNode delNthFromLast(pNode pHead, int k) {
    // 1 2 3 4 5 6
    //       x
    //     p1 ->
    // p2 ->

    // 1. cal linkedlist len
    while() {
        ...
        n++;
    }

    pNode pDummy = new LinkedList(0);
    pDummy->next = pHead;
    pNode p1 = pHead;
    pNode p2 = pHead;

    for(int i = 0; i < n - k; i++) {
        p1 = p1->next;
    }
    p1 = p1->next;
    for(; p1 != nullptr; ) {
        p1 = p1->next;
        p2 = p2->next;
    }

    pNode pTmp = p2->next;
    p2->next = p2->next->next;
    free(pTmp);
    return pDummy->next;
}

// 1. len of linkedlist a
// 2. len of linkedlist b
longer = a;
shorter = b;
longer travel to lenA - lenB
// 3. travel from a and b, until they are equal

// 1. fast 2x slow
// 2. if fast not reach to nullptr, and they meet
// 3. fast from begin speed change to 1x slow
// 4. return the meet point

for(int i = 0; i < n; i++) {
    lhs = i + 1;
    rhs = n - 1;
    while(lhs < rhs) {
        if(total == 0) pushback();
        else if > 0
            rhs--;
            ...
        else if < 0
            ...
            lhs++;
    }
}


int main(void) {
    Robot robot;
    cleanRoom(robot);
    
    // vector<int> v{12, 7, 111, 15};
    
    // sort(v.begin() + 1, v.end());
    // for(auto it : v) {
    //     cout << it << endl;
    // }
    return 0;
}

// pthread_mutex_t mutex;
// sem_t full;
// sem_t empty;

// void* producer(void* arg) {
//     int item = 0;
//     while(1) {
//         pthread_testcancel();
//         sem_wait(&empty);
//         pthread_mutex_lock(&mutex);

//         pthread_mutex_unlock(&mutex);
//         sem_post(&full);
//         sleep(1);
//     }
// }


// vector<int> twoSum(vector<int>& nums, int target) {

// }

// int main(int argc, char* argv[]) {
//     vector<int> nums{2, 7, 11, 15};
//   twoSum(nums, 9);

//     return 0;
// }

// int main(void) {
//     pthread_t pth[3];
//     for(long i = 0; i < 3; i++) {
//         pthread_create(&pth[i], nullptr, producer, (void*)i);
//     }

//     for(long i = 0; i < 3; i++) {
//         pthread_join(pth[i], nullptr);
//     }

//     return 0;
// }