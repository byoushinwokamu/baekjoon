#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int r;
  cin >> r;
  double eu = M_PI * r * r;
  double ta = 2 * r * r;
  cout.precision(11);
  cout << fixed << eu << "\n" << ta;

  return 0;
}