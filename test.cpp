


#include "test.hpp"
#include <thread>

using namespace std;

<<<<<<< HEAD
/*
// TODO
ok - meeting room
# - aligned memory
- bitwise
ok - blur
- dp --------

ok - delete adjacent dup
ok - remove dup for array

ok - remove dup for linkdelist
ok - remove additional spaces

- sink island
ok - spiral mat
ok - reverse ll
- kmp
*/


int test(vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;
    for (; left <= right;) {
        int mid = (left + right) / 2;
        if (nums[mid] == val) {
            return mid;
        }
        // 如果 中数小于最右边的数，那么 - 右半段是有序的！ - 看看是不是在右边
        if (nums[mid] < nums[right]) {
            if (val > nums[mid] && val <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // 如果 中数大于最右边的数，那么 - 左半段是有序的！ - 看看是不是在左边
        else {
            if (val < nums[mid] && val >= nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    cout << test(nums, 0);
    // cout << s << endl;
=======
class Robot {
public:
    Robot() {}

    void turnRight() {
        cout << "turnRight\n";
    }
    bool move() {
        if()
        cout << "move\n";
    }
    void clean() {
        cout << "clean\n";
    }

private:
    // 0: obstacle
    // 1: accasble
    int x, y;
    int dir;
    vector<vector<int>> map = { {1, 1, 0},
                                {0, 0, 1}, 
                                {1, 1, 1}, 
                                {1, 0, 1}};
};



// void dfs(vector<int>& nums, int pos) {
//     int n = nums.size();
//     // if(pos >= n) {
//     //     return;
//     // }
//     for(int i = 0; i < n; i++) {
//         if(nums[i] != 0) {
//             dfs(nums, pos + 1);
//             cout << i << endl;
//         }
//     }
// }

void dfs(Robot& robot, set<pair<int, int>>& visited, int i, int j, int dir) {
    robot.clean();
    visited.insert(pair{i, j});
    int n = visited.size();

    // vector<pair<int, int>> v;
    // std::copy(visited.begin(), visited.end(), back_inserter(v));

    // for(auto pair : v) {
    //     cout << pair.first << " " << pair.second << endl;
    // }

    // for_each(visited.begin(), visited.end(), [](pair<int, int> pair) {
    //     cout << pair.first << " " << pair.second << endl;
    // });

    pair<int, int> direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for(int k = 0; k < 4; k++) {
        int new_i = i + direction[dir].first;
        int new_j = j + direction[dir].second;

        // the new coordinate were NOT visited and robot can move in
        if(visited.count({new_i, new_j}) == 0 && robot.move()) {
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

int main(void) {
    // vector<int> nums = {1, 2, 3, 0, 5};
    Robot robot;
    set<pair<int, int>> visited;
    dfs(robot, visited, 10, 20, 0);
>>>>>>> 4783818 (read2)

    return 0;
}