

#include <thread>

using namespace std;


    string s = "1234567890";
    set<string> Set;

// string truncate, and inset to Set
    Set.insert(s.substr(0, 3));
    Set.insert(s.substr(3, 3));
    Set.insert(s.substr(6, 3));

// 1. the first element:
    cout << *Set.begin() << endl;

// 1. the last element:
    cout << *Set.rbegin() << endl;




// multiset: allow repeat elements in set
void demo_multiset() {
    std::unordered_multiset<string> set;
    set.insert("Shawn");
    set.insert("Julie");
    set.insert("Shawn");

    for(auto it : set) {
        cout << it << " ";
    }
    cout << endl;
}


class Robot {
public:
    Robot() {}

    void turnRight() {
        cout << "turnRight\n";
    }
    void move() {
        cout << "move\n";
    }
    void clean() {
        cout << "clean\n";
    }

private:
    // 0: obstacle
    // 1: accasble
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

    vector<pair<int, int>> v;
    std::copy(visited.begin(), visited.end(), back_inserter(v));

    for(auto pair : v) {
        cout << pair.first << " " << pair.second << endl;
    }

    for_each(visited.begin(), visited.end(), [](pair<int, int> pair) {
        cout << pair.first << " " << pair.second << endl;
    });
}

int main(void) {
    // vector<int> nums = {1, 2, 3, 0, 5};
    Robot robot;
    set<pair<int, int>> visited;
    dfs(robot, visited, 10, 20, 0);

    return 0;
}