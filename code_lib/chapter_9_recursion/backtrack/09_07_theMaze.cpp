
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

        while(row >= 0 && row < m && col >= 0 && row < n && maze[row][col] == 0) {
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