/*  [104]
    find islands
*/
void sink_island(char **s, int i, int j, int gridSize, int gridColSize) {
    if(i < 0 || i >= gridSize)      return;
    if(j < 0 || j >= gridColSize)   return;
    if(s[i][j] == 0)                return;

    s[i][j] = '0';
    sink_island(s, i + 1, j, gridSize, gridColSize);
    sink_island(s, i - 1, j, gridSize, gridColSize);
    sink_island(s, i, j + 1, gridSize, gridColSize);
    sink_island(s, i, j - 1, gridSize, gridColSize);
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