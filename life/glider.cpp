#include <iostream>
#include <vector>
#include <unistd.h>
#include <termios.h>
#include <ncurses.h>

#define ROW 5
#define COL 5

void initMatrix(std::vector<std::vector<bool>>& mat) {
    mat.resize(ROW, std::vector<bool>(COL, false));

    // Glider pattern
    mat[1][2] = true;
    mat[2][3] = true;
    mat[3][1] = true;
    mat[3][2] = true;
    mat[3][3] = true;
}

void showMe(const std::vector<std::vector<bool>>& mat) {
    system("clear");

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (mat[i][j])  std::cout << "* ";
            else            std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

int neighbourNum(const std::vector<std::vector<bool>>& mat, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // itself
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < ROW && newY >= 0 && newY < COL) {
                count += mat[newX][newY] ? 1 : 0;
            }
        }
    }
    return count;
}

void update(std::vector<std::vector<bool>>& mat) {
    std::vector<std::vector<bool>> newMat = mat;

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            int adj = neighbourNum(mat, i, j);
            if (mat[i][j]) {    // if alive
                if (adj < 2 || adj > 3) // neighbours are less than 2 or more than 3
                    newMat[i][j] = false;
            } else {    // if dead
                if (adj == 3)   // neighbours are 3
                    newMat[i][j] = true;
            }
        }
    }

    int indexX = 0;
    for( ; indexX < COL; indexX++) {
        if(newMat[1][indexX] == true) {
            break;
        }
    }

    if(indexX == COL){
        for(int i = 0; i < ROW - 1; i++) {
            for(int j = 0; j < COL; j++) {
                mat[i][j] = newMat[i + 1][j];
            }
        }
    }

    int indexY = 0;
    for( ; indexY < ROW; indexY++) {
        if(newMat[indexY][1] == true) {
            break;
        }
    }

    if(indexY == ROW){
        for(int i = 0; i < COL; i++) {
            for(int j = 0; j < ROW - 1; j++) {
                mat[i][j] = newMat[i][j + 1];
            }
        }
    }

    if(indexX != COL && indexY != ROW)
        mat = newMat;
}

int main() {
    std::vector<std::vector<bool>> mat;
    initMatrix(mat);

    // getch();
    // std::cin.get();
    // std::cout << "gogogo" << std::endl;

    // return 0;

    while (true) {
        showMe(mat);
        std::cin.get(); // press enter to continue

        update(mat);

        // usleep(1000000); // Sleep for 1s
    }

    return 0;
}
