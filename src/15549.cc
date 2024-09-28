#include <iostream>
using namespace std;
int main() {
  for (int x = INT32_MIN; x <= INT32_MAX; x++) {
    if (x != 0 && x == -x)
      cout << x << endl;
    else
      continue;
  }
}