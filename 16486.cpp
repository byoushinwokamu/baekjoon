#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  cout.precision(11);
  cout << (static_cast<double>(2 * a) + M_PI * b * 2);

  return 0;
}