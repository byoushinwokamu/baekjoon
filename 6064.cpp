#include <iostream>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  for (int test = 0; test < t; test++) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    // x %= m;
    y %= n;
    int l = lcm(m, n);
    int md = l / m;
    int nd = l / n;
    int i;
    for (i = 0; i <= md; i++) {
      if ((i * m + x) % n == y) {
        cout << i * m + x << '\n';
        break;
      }
    }
    if (i > md)
      cout << "-1\n";
  }

  return 0;
}