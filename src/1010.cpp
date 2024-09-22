#include <cmath>
#include <iostream>

using namespace std;

long long fac(int f, int s) {
  long long r = 1;
  for (int i = s; i <= f; i++)
    r *= i;
  return r;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  long long n, m;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    if (n * 2 < m)
      n = m - n;
    cout << (fac(m, n + 1) / fac(m - n, 1)) << '\n';
  }
  return 0;
}