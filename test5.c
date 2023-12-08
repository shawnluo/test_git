#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 15
#define MAX_COLS 15

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    char direction;
} QueueNode;

typedef struct {
    QueueNode data[MAX_ROWS * MAX_COLS];
    int front, rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

void enqueue(Queue *queue, Point point, char direction) {
    if (queue->rear == MAX_ROWS * MAX_COLS - 1) {
        printf("Queue is full\n");
        exit(EXIT_FAILURE);
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->data[queue->rear].point = point;
    queue->data[queue->rear].direction = direction;
}

QueueNode dequeue(Queue *queue) {
    QueueNode node;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    node = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return node;
}

int isValid(int x, int y, int rows, int cols, char grid[MAX_ROWS][MAX_COLS]) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != '#';
}

void markPath(char grid[MAX_ROWS][MAX_COLS], Point start, Point end, char direction) {
    int x = end.x;
    int y = end.y;

    while (x != start.x || y != start.y) {
        grid[x][y] = 'x';

        if (direction == 'U') x--;
        else if (direction == 'D') x++;
        else if (direction == 'L') y--;
        else if (direction == 'R') y++;

        direction = grid[x][y];
    }
}

void shortestPath(char grid[MAX_ROWS][MAX_COLS], int rows, int cols) {
    Queue queue;
    initQueue(&queue);

    Point start, end;

    // Find the starting and ending positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'S') {
                start.x = i;
                start.y = j;
            } else if (grid[i][j] == 'E') {
                end.x = i;
                end.y = j;
            }
        }
    }

    enqueue(&queue, start, ' ');

    while (!isEmpty(&queue)) {
        QueueNode current = dequeue(&queue);
        Point currentPoint = current.point;

        // Check if we reached the end
        if (currentPoint.x == end.x && currentPoint.y == end.y) {
            markPath(grid, start, currentPoint, current.direction);
            return;
        }

        // Explore neighbors (U, D, L, R)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = currentPoint.x + dx[i];
            int newY = currentPoint.y + dy[i];

            if (isValid(newX, newY, rows, cols, grid)) {
                enqueue(&queue, (Point){newX, newY}, "UDLR"[i]);
                grid[newX][newY] = '#'; // Mark the visited position
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    char grid[MAX_ROWS][MAX_COLS] = {
        "###############",
        "##E.....#######",
        "#######......##",
        "#######......##",
        "##......#######",
        "##......#######",
        "#######......##",
        "#######......##",
        "##.....##.#####",
        "##......#.#####",
        "#######......##",
        "#######......##",
        "##......#######",
        "##..........S##",
        "###############",
    };

    int rows = sizeof(grid) / sizeof(grid[0]);
    int cols = strlen(grid[0]);

    // Find and mark the shortest path
    shortestPath(grid, rows, cols);

    // Print the grid with the traced path
    for (int i = 0; i < rows; i++) {
        printf("%s\n", grid[i]);
    }

    return 0;
}
