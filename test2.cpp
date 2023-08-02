#include "test.hpp"

// using namespace std;
 
int main()
{
    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 4, 5, 6 };
 
    // swapping the above two vectors
    // by traversing and swapping each element
    for (int i = 0; i < 3; i++) {
        std::swap(v1[i], v2[i]);
    }
 
    // print vector v1
    cout << "Vector v1 = ";
    for (int i = 0; i < 3; i++) {
        cout << v1[i] << " ";
    }
 
    // print vector v2
    cout << "\nVector v2 = ";
    for (int i = 0; i < 3; i++) {
        cout << v2[i] << " ";
    }
 
    return 0;
}