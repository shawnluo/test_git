
#include "test.hpp"

#include <iostream>
#include <memory>
#include <vector>

// Custom deleter
struct VectorDeleter {
    void operator()(std::vector<int>* ptr) const {
        std::cout << "Deleting vector of size " << ptr->size() << std::endl;
        delete ptr;
    }
};

void test() {
    // Type alias for unique_ptr with custom deleter
    using IntVectorPtr = std::unique_ptr<std::vector<int>, VectorDeleter>;

    // Initialize the unique_ptr with a new vector<int> and the custom deleter
    IntVectorPtr vecPtr(new std::vector<int>{1, 2, 3, 4, 5}, VectorDeleter());

    // Use the unique_ptr
    for (int value : *vecPtr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}
