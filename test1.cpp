
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

int exploreIslands1(char** s, int i, int j, int gridSize, int gridColSize) {
    if(i < 0 || i >= gridSize)      return;
    if(j < 0 || j >= gridColSize)   return; 
    if(s[i][j] == 0)                return;

    s[i][j] = '0';
    sinkIsland(s, i + 1, j,     gridSize, gridColSize);
    sinkIsland(s, i - 1, j,     gridSize, gridColSize);
    sinkIsland(s, i,     j + 1, gridSize, gridColSize);
    sinkIsland(s, i,     j - 1, gridSize, gridColSize);
}

void exploreIslands(vector<int, int>& s, int i, int j) {
    int row = s.size();
    int col = s[0].size();
    if((i < 0 || i > row) || (j < 0 || j > col)) {
        return;
    }
    
    if(s[i][j] == 1) {
        s[i][j] = 0;
    }

    vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for(int i = 0; i < 4; i++) {
        exploreIslands(s, i + direction[i].first, j + direction[i].second);
    }
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


void dfs(Robot& robot, set<int, int>& visited, int i, int j, int dir) {
    robot.clean();
    visited.insert(i, j);
    vector<pair<int, int>> direction = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    for(int i = 0; i < 4; i++) {
        /*  if next step is legal
                call dfs

            turn right
        */ 
        int iNew = i + direction[dir].first;
        int jNew = j + direction[dir].second;
        if(robot.forward() && visited.find([iNew], [jNew]) == visited.end) {
            dfs(robot, visited, iNew, jNew, dir);
            robot.turnRight();
            robot.turnRight();
            robot.forward();
            robot.turnRight();
            robot.turnRight();
        }
        dir = (dir + 1) % 4;
        robot.turnRight();
    }
}

void cleanRoom(Robot& robot) {
    set<int, int> visited;
    dfs(robot, visited, 0, 0, 0);
}

// (1, 2) (2, 4) (3, 5)
int meetingRoom(vector<vector<int, int>> rooms) {
    int n = rooms.size();
    vector<int> start, end;
    for(int i = 0; i < n; i++) {
        start.push_back(rooms[i][0]);
        end.push_back(rooms[i][1]);
    }
    int res = 1;
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(start[i] < end[j]) {
            res++;
        } else {
            j++;
        }
    }
    return res;
}

void* alignedMalloc(size_t len, size_t alignment) {
    // 1. the newLen
    // 2. the address
    // 3. the newAddress
    // 4. for free
    // 5. return newAddress

    size_t offset = alignment - 1;
    size_t newLen = len + offset + sizeof(size_t);
    size_t* addr = (size_t*)malloc(newLen);
    size_t* newAddr = addr & (~offset);
    *(newAddr - 1) = newAddr - addr;

    return newAddr;
}

void* alignedMemcpy(void* src, void* dst, size_t srcLen, size_t dstLen, size_t alignment) {
    // 1. the newDst
    //  1). need malloc new address?
    //  2). if no, then just offset to start of alignment
    // 2. memcpy
    size_t* newDst = (size_t*)dst;
    size_t* src_ = (size_t*)src;

    size_t offset = alignment - 1;
    newDst = newDst + offset;

    char* dstChar = (char*)newDst;
    char* srcChar = (char*)src;
    for(int i = 0; i < srcLen; i++) {
        *dstChar++ = *srcChar++;
    }

    *(dst - 1) = newDst - (size_t*)dst;;

    return NewDst;
}

// 从n个物品中，选取装满背包BAG，不得重复选取。求最大价值
int dp_11(vector<int>& weight, vector<int>& value, int BAG) {
    int size = weight.size();
    vector<vector<int>> dp(size, vector<int> (BAG + 1, 0 ));

    for(int j = weight[0]; j <= BAG; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 1; i < size; i++) {
        for(int j = 0; j <= BAG; j++) {
            if(j >= weight[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - weight[i]][j] + value[i]);
            }
        }
    }
    return dp[size - 1][BAG];
}

int dp_12(vector<int>& weight, vector<int>& value, int BAG) {
    int size = weight.size();
    vector<int> dp(BAG + 1, 0);

    for(int i = 0; i < size; i++) {
        for(int j = BAG; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[BAG];
}