
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


#include <iostream>
#include <string>


int main() {
    cout << sizeof(size_t) << endl;

    return 0;
}

void sinkIsland(char** s, int i, int j, int gridSize, int gridColSize) {

}

int exploreIslands(char** s, int i, int j, int gridSize, int gridColSize) {
    if(i < 0 || i >= gridSize)      return;
    if(j < 0 || j >= gridColSize)   return; 
    if(s[i][j] == 0)                return;

    s[i][j] = '0';
    sinkIsland(s, i + 1, j,     gridSize, gridColSize);
    sinkIsland(s, i - 1, j,     gridSize, gridColSize);
    sinkIsland(s, i,     j + 1, gridSize, gridColSize);
    sinkIsland(s, i,     j - 1, gridSize, gridColSize);
}


/*
    robot.move()()      : robot move forward, return true if success, return false if abstacle is there or out of border
    robot.turnRight()   : robot turn right
*/
void dfs(Robot& robot, set<pair<int, int>>& visited, int i, int j, int dir) {
    robot.clean();
    visited.insert({i, j});
    pair<int, int> direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for(int k = 0; k < 4; k++) {
        int new_i = i + directions[dir].first;
        int new_j = j + directions[dir].second;
        if(visited.count({new_i, new_j}) == 0 && robot.move()) {
            dfs(robot, visited, new_i, new_j, dir);

            // 如果
            robot.turnRight();
            robot.turnRight();
            robot.move();
            robot.turnRight()
            robot.turnRight();
        }
        dir = (dir + 1) % 4;
        robot.turnRight();
    }
}

void cleanRoom(Robot& robot) {
    set<pair<int, int>> visited;
    dfs(robot, visited, 0, 0, 0);
}