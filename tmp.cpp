
#include "test.hpp"

#define SOUND_CTL *(volatile unsigned long*)0x80000000

#define CTL (unsigned long*)0x80000000

int main() {
    vector<int> v = {1, 2, 3, 4};
    auto it = find(v.begin() + 3, v.end(), 3);
    if (it != v.end()) {
        std::cout << "Value 3 found at index: " << std::distance(v.begin(), it) << std::endl;
    } else {
        std::cout << "Value 3 not found in the vector" << std::endl;
    }

    return 0;
}