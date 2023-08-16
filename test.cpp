#include "test.hpp"



vector<int> removeSq(vector<int>& nums) {
    // if(nums == nullptr) {
        // return "";
    // }

    int size = nums.size();
    int left = 0;
    int right = size - 1;
    vector<int> res(nums.size(), 0);

    while(left < right) {
        if(nums[left] * nums[left] < nums[right] * nums[right]) {
            res[--size] = nums[right] * nums[right];
            right--;
        } else {
            res[--size] = nums[left] * nums[left];
            left++;
        }
    }

    return res;
}

void test() {
    vector<int>& des = {4, 4};
}

int main(void) {
    vector<int> nums = {-5, -3, -1, 1, 3, 6, 9};
    vector<int> res = removeSq(nums);
    for(auto x : res) {
        cout << x << endl;
    }

    return 0;
}

//=================================

void find_clear(char **s, int i, int j, int gridSize, int gridColSize) {
    if(i < 0 || i >= gridSize || j < 0 || j >= gridColSize) {
        return;
    }
    if(s[i][j] == '1') {
        s[i][j] = '0';
        find_clear(s, i + 1, j, gridSize, gridColSize);
        find_clear(s, i - 1, j, gridSize, gridColSize);
        find_clear(s, i, j + 1, gridSize, gridColSize);
        find_clear(s, i, j - 1, gridSize, gridColSize);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid == 0 || gridSize == 0 || *gridColSize == 0) {
        return 0;
    }
    //1. find 1, then reverse it and 1s connected with it. counter + 1
    //2. scan the rest of grid. repeat 1, until all 1s become zero
    int count = 0, i, j;
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < *gridColSize; j++) {
            if(grid[i][j] == '1') {
                find_clear(grid, i, j, gridSize, *gridColSize);
                count++;
            }
        }
    }
    return count;
}

bool dfs(int m, int n, vector<vector<int>>& maze, vector<int> curr, vector<int>& destination, vector<vector<bool>>& visit) {
    if(visit[curr[0]][curr[1]]) {
        return false;
    }
    if(curr == destination) {
        return true;
    }

    visit[curr[0]][curr[1]] = true;
    vector<int> dirX{0, 1, 0, -1};
    vector<int> dirY{-1, 0, 1, 0};

    for(int i = 0; i < 4; i++) {
        int row = curr[0];
        int col = curr[1];

        while(row >= 0 && row < m && col >= 0 && c < n && maze[row][col] == 0) {
            row += dirX[i];
            col += dirY[i];
        }

        if(dfs(m, n, maze, {row - dirX[i], col - dirY[i]}, destination, visit)) {
            return true;
        }
    }
    return false;
}

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visit(m, vector<bool> (n));
    
    return dfs(m, n, start, destination, visit);
}