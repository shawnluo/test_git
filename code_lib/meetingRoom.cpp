

/*
    根据nums的起始时间点，确定需要多少房间才能满足
*/
int meetingRoom(vector<vector<int>> nums) {
    int room = 0;

    vector<int> start;
    vector<int> end;

    for(auto x : nums) {
        start.push_back(x[0]);
        end.push_back(x[1]);
    }

    int pEnd = 0;
    for(int pStart = 0; pStart < nums.size(); pStart++) {
        if(pStart == 0 && start[pStart] < end[pEnd]) {
            room++;
        } else {
            pEnd++;
        }
    }

    return room;
}