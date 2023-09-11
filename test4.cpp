#include "test.hpp"



int main() {
    const char* strings[] = { "Hello", "World", "C++" };
    int arrayLength = sizeof(strings) / sizeof(strings[0]);

    std::cout << "Number of strings: " << arrayLength << std::endl;

    return 0;
}