#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>


// C++ program to demonstrate
// multithreading using three
// different callables.
#include <iostream>
#include <thread>
using namespace std;

class Robot {
public:
    Robot(int i, int j);

    void turnRight();
    bool move();
    void clean();
    int getX();

private:
    // 0: obstacle
    // 1: accasble
    int x, y;
    int dir;
    int row = map.size();
    int col = map[0].size();
    vector<vector<int>> map = { {1, 1, 0},
                                {0, 0, 1}, 
                                {1, 1, 1}, 
                                {1, 0, 1}};
};

Robot::Robot(int i, int j) : x(i), y(j) {
    cout << "constructor: x: " << x << " - y: " << y << endl;
}

void Robot::clean() {
    cout << "clean\n";
}

int Robot::getX() {
    return x;
}

void Robot::turnRight() {
    cout << "turnRight\n";
}

bool Robot::move() {
    switch(dir) {
        case 0:
            y--;
            if(map[x][y] == 0 || y < 0 || y >= col) {
                return false;
            }
            break;

        case 1:
            x++;
            if(map[x][y] == 0 || x < 0 || x >= row) {
                return false;
            }
            break;
    }

    return true;
}


int main(void) {
    Robot robot(113, 4);
    // cout << robot.getX() << endl;


    // unordered_set<int> Set;
    // Set.insert(5);

    // cout << Set.count(5);

    return 0;
}