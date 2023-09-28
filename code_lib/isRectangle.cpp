inline float getLength(int ax, int ay, int bx, int by) {
    float resX = abs(ax - bx);
    float resY = abs(ay - by);

    resX = pow(resX, 2);
    resY = pow(resY, 2);

    return sqrt(resX + resY);
}

bool isRectangle(vector<vector<int>> nums) {
    // cal the length of 6 lines
    vector<int> lines(4, 0);
    
    float line0 = getLength(nums[0][0], nums[1][0], nums[0][1], nums[1][1]);
    float line1 = getLength(nums[0][0], nums[2][0], nums[0][1], nums[2][1]);
    float line2 = getLength(nums[0][0], nums[3][0], nums[0][1], nums[3][1]);
    float line3 = getLength(nums[1][0], nums[2][0], nums[1][1], nums[2][1]);
    float line4 = getLength(nums[1][0], nums[3][0], nums[1][1], nums[3][1]);
    float line5 = getLength(nums[2][0], nums[3][0], nums[2][1], nums[3][1]);

    lines.push_back();
    // sorting them
    if(nums[0] == nums[1] && \
        nums[2] == nums[3] && \
        nums[4] == nums[5]) {
        if(nums[4] * nums[4] = nums[0] * nums[0] + nums[2] * nums[2]) {
            return true;
        }
    }
    return false;
}