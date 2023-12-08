/* 
the program is supposed to find the shortest path from S to E from a grid from 
my Input where the size is also my input, using the BFS method, the supposed 
Output is the reprinted grid with a traced path where the shortest path is
here is the test case and expected output
input:
15 15
###############
##E.....#######
#######......##
#######......##
##......#######
##......#######
#######......##
#######......##
##......#######
##......#######
#######......##
#######......##
##......#######
##..........S##
###############

expected output:
###############
##Exxxxx#######
#######x.....##
#######x.....##
##.....x#######
##.....x#######
#######x.....##
#######x.....##
##.....x#######
##.....x#######
#######x.....##
#######x.....##
##.....x#######
##.....xxxxxS##
###############
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Cell {
    int x, y;
};

struct Queue {
    int front, rear, size;
    struct Cell array[MAX_SIZE * MAX_SIZE];
};

struct Grid {
    int maxX, maxY;
    char grid[MAX_SIZE][MAX_SIZE];
    struct Queue queue;
};

struct Cell newCell(int x, int y) {
    struct Cell cell = {x, y};
    return cell;
}

void createQueue(struct Queue* queue, int capacity) {
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
}

bool isValid(int x, int y, struct Grid* grid) {
    return (x >= 0) && (y >= 0) && (x < grid->maxX) && (y < grid->maxY);
}

bool isWalkable(int x, int y, struct Grid* grid) {
    return (grid->grid[x][y] == '.' || grid->grid[x][y] == 'E');
}

bool isFinish(int x, int y, struct Grid* grid) {
    return grid->grid[x][y] == 'E';
}

void shortestPath(struct Grid* grid, int startX, int startY) {
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    bool visited[MAX_SIZE][MAX_SIZE];
    struct Cell parent[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < grid->maxX; ++i) {
        for (int j = 0; j < grid->maxY; ++j) {
            visited[i][j] = false;
            parent[i][j] = newCell(-1, -1);
        }
    }

    visited[startX][startY] = true;
    grid->queue.front = 0;
    grid->queue.rear = 0;
    grid->queue.size = 1;
    grid->queue.array[grid->queue.rear] = newCell(startX, startY);

    while (grid->queue.size != 0) {
        struct Cell current = grid->queue.array[grid->queue.front];
        grid->queue.front = (grid->queue.front + 1) % (MAX_SIZE * MAX_SIZE);
        grid->queue.size--;

        if (isFinish(current.x, current.y, grid)) {
            // Trace the path and mark it with 'X'
            int x = current.x, y = current.y;
            while (parent[x][y].x != -1 && parent[x][y].y != -1) {
                grid->grid[x][y] = 'X';
                int tempX = parent[x][y].x;
                int tempY = parent[x][y].y;
                x = tempX;
                y = tempY;
            }
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, grid) && !visited[newX][newY] && isWalkable(newX, newY, grid)) {
                visited[newX][newY] = true;
                parent[newX][newY] = current;
                grid->queue.rear = (grid->queue.rear + 1) % (MAX_SIZE * MAX_SIZE);
                grid->queue.size++;
                grid->queue.array[grid->queue.rear] = newCell(newX, newY);
            }
        }
    }
}


void printGrid(struct Grid* grid) {
    for (int i = 0; i < grid->maxX; ++i) {
        for (int j = 0; j < grid->maxY; ++j) {
            printf("%c ", grid->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maxX, maxY;
    scanf("%d %d", &maxX, &maxY);
    struct Grid grid;
    grid.maxX = maxX;
    grid.maxY = maxY;

    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            char ch;
            scanf(" %c", &ch);
            grid.grid[i][j] = ch;
        }
    }

    shortestPath(&grid, 0, 0);

    printGrid(&grid);

    return 0;
}
