#include "test.hpp"


int main(void) {
    std::unordered_map<char, int> umap;
    for(int i = 0; i < 255; i++) {
        umap[i] = i;
    }

    cout << umap[2] << endl;

    

    return 0;
}