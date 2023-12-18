/*  [104]
    find islands
*/
void sink_island(char **s, int x, int y, int gridSize, int gridColSize) {
    if(x < 0 || y >= gridSize)      return;
    if(y < 0 || y >= gridColSize)   return;
    if(s[x][y] == 0)                return;

    s[x][y] = '0';
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for(int i = 0; i < 4; i++) {
        sink_island(s, x + dir[i][0], y + dir[i][1], gridSize, gridColSize);
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
                sink_island(grid, i, j, gridSize, *gridColSize);
                count++;
            }
        }
    }
    return count;
}