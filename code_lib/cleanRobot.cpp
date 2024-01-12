/* robot clean room */
#include "../test.hpp"
using namespace std;

class Robot {
public:
    Robot();
    bool move();
    void clean();
    void turnRight();
};

void dfs(Robot& robot, set<pair<int, int>>& visited, int i, int j, int dir) {
    robot.clean();
    visited.insert({i, j});
    
    vector<pair<int, int>> directions = {
        {-1,  0}, //up
        { 0,  1}, //right
        { 1,  0}, //down
        { 0, -1}  //left
    };

    for(int k = 0; k < 4; k++) {
        int new_i = i + directions[dir].first;
        int new_j = j + directions[dir].second;

        // 如果[newI, newJ]是有效的访问点，则进行访问
        if(robot.move() && visited.count({new_i, new_j}) == 0) {
            dfs(robot, visited, new_i, new_j, dir);

            // 访问完[newI, newJ]之后，回退到[i, j]。
            robot.turnRight();
            robot.turnRight();
            robot.move();
            robot.turnRight();
            robot.turnRight();
        }

        // 访问完之后，右转。
        dir = (dir + 1) % 4;
        robot.turnRight();
    }
}

void cleanRoom(Robot& robot) {
    std::set<pair<int, int>> visited;

    dfs(robot, visited, 
    0, /* i */
    0, /* j */
    0 /* dir */
    ); 
}