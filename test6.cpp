#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define MAX_ROWS 15
#define MAX_COLS 15

struct Point {
    int x, y;
};

bool isValid(int x, int y, int rows, int cols, vector<string> &grid) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != '#';
}

void findShortestPath(vector<string> &grid, Point start, Point end, \
                        vector<string> &shortestPathGrid, \
                        int &minSteps, \
                        int steps) {
    if (start.x == end.x && start.y == end.y) {
        if (steps < minSteps) {
            minSteps = steps;
            shortestPathGrid = grid;
        }
        return;
    }

    if (!isValid(start.x, start.y, grid.size(), grid[0].size(), grid) \
            || grid[start.x][start.y] == 'v' \
            || steps >= minSteps) {
        return;
    }

    char original = grid[start.x][start.y];
    grid[start.x][start.y] = 'v';  // Mark as visited

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newX = start.x + dx[i];
        int newY = start.y + dy[i];

        findShortestPath(grid, {newX, newY}, end, shortestPathGrid, minSteps, steps + 1);
    }

    grid[start.x][start.y] = original;  // Restore the original value
}

void shortestPath(vector<string> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    Point start, end;

    // Find the starting and ending positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'E') {
                end = {i, j};
            }
        }
    }

    int minSteps = INT_MAX;
    vector<string> shortestPathGrid;

    findShortestPath(grid, end, start, shortestPathGrid, minSteps, 0);

    if (minSteps != INT_MAX) {
        cout << "Shortest path found with " << minSteps << " steps." << endl;
        shortestPathGrid[end.x][end.y] = 'E';  // Restore 'E'
        grid = shortestPathGrid;
    } else {
        cout << "No path found." << endl;
    }
}

int main() {
    vector<string> grid = {
        "###############",
        "##E.....#######",
        "#######......##",
        "#######......##",
        "##......#######",
        "##......#######",
        "####.##......##",
        "#######.......#",
        "##.....######.#",
        "##......##....#",
        "#######....####",
        "#######......##",
        "##......#######",
        "##..........S##",
        "###############",
    };

    // Find and mark the shortest path
    shortestPath(grid);

    // Print the grid with the traced path
    for (const string &row : grid) {
        cout << row << endl;
    }

    return 0;
}
