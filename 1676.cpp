#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int re2 = 0, re5 = 0;
  for (int i = n; i > 1; i--) {
    int temp = i;
    while (temp % 2 == 0)
      re2++, temp /= 2;
    while (temp % 5 == 0)
      re5++, temp /= 5;
  }
  cout << (re2 < re5 ? re2 : re5);

  return 0;
}