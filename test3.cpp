

#include <iostream>
#include <vector>
#include <algorithm>

// Comparison function for sorting the 2D vector
bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    // Compare the first element of each vector
    if(a[0] == b[0]) {
        // return a[1] < b[1];
    }
    return a[0] < b[0];
}

int main() {
    std::vector<std::vector<int>> vec = {
        {3, 2},
        {1, 7},
        {1, 4},
        {1, -1},
        {2, 3}
    };

    // Sort the 2D vector using sort
    // std::sort(vec.begin(), vec.end(), compare);
    std::sort(vec.begin(), vec.end());

    // Print the sorted vector
    for (const auto& row : vec) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}