/* robot clean room */
void dfs(Robot& root, set<pair<int, int>>& visited, int i, int j, int dir) {
    robot.clean();
    visited.insert(i, j);
    
    vector<pair<int, int>> director = {
        {-1,  0}, //up
        { 0,  1}, //right
        { 1,  0}, //down
        { 0, -1}  //left
    };

    for(int i = 0; i < 4; i++) {
        int newI = i + direction[dir].first;
        int newJ = j + direction[dir].second;

        // 如果[newI, newJ]是有效的访问点，则进行访问
        if(robot.move() && visited.count({newI, newJ}) == 0) {
            dfs(root, visited, newI, newJ, dir);

            // 访问完[newI, newJ]之后，回退到[i, j]。
            robot.turnRight();
            robot.turnRight();
            robot.move();
            robot.turnRight();
            robot.turnRight();
        }

        // 访问完之后，右转。
        dir = (dir + 1) % 4;
        root.turnRight();
    }
}

void cleanRoom(Robot& robot) {
    set<pair<int, int>> visited;
    dfs(robot, visited, 
    0, /* i */
    0, /* j */
    0 /* dir */
    ); 
}