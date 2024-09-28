#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int r, g, b;
  cin >> r >> g >> b;
  if ((r % 3 > 0 && g % 3 == 0 && b % 3 == 0) ||
      (r % 3 == 0 && g % 3 > 0 && b % 3 == 0) ||
      (r % 3 == 0 && g % 3 == 0 && b % 3 > 0))
    cout << (r / 3 + g / 3 + b / 3 + 1);
  else
    cout << (r / 3 + g / 3 + b / 3 + max({r % 3, g % 3, b % 3}));

  return 0;
}