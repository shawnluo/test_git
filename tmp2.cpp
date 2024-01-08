#include <pthread.h>
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

#include <iostream>
#include <cmath>

int main() {
  double x = 5.14;
  int y = ceil(x);

  std::cout << "The ceil of " << x << " is " << y << std::endl;

  return 0;
}