from collections import deque

def shortest_path(grid):
    rows, cols = len(grid), len(grid[0])
    start, end = None, None

    # Find the starting and ending positions
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 'S':
                start = (i, j)
            elif grid[i][j] == 'E':
                end = (i, j)

    # Function to check if a position is valid
    def is_valid(x, y):
        return 0 <= x < rows and 0 <= y < cols and grid[x][y] != '#'

    # Perform BFS to find the shortest path
    queue = deque([(start, [])])
    visited = set()

    while queue:
        (x, y), path = queue.popleft()

        if (x, y) == end:
            # Mark the shortest path on the grid
            for (i, j) in path:
                grid[i][j] = 'x'
            return

        if (x, y) not in visited:
            visited.add((x, y))

            # Explore neighbors
            neighbors = [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]
            for nx, ny in neighbors:
                if is_valid(nx, ny):
                    queue.append(((nx, ny), path + [(nx, ny)]))

# Example grid
input_grid = [
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
]

# Convert the input grid to a list of lists
input_grid = [list(row) for row in input_grid]

# Find and mark the shortest path
shortest_path(input_grid)

# Print the grid with the traced path
for row in input_grid:
    print(''.join(row))
