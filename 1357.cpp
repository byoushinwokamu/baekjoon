#include <iostream>

using namespace std;

int rev(int n) {
  int r = 0;
  while (n != 0)
    r *= 10, r += n % 10, n /= 10;
  return r;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;
  cout << rev(rev(x) + rev(y));

  return 0;
}