#include <cmath>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m;
  int a = -1, b, c, d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> k;
      if (k && a == -1)
        a = i, b = j;
      else if (k)
        c = i, d = j;
    }
  }
  cout << abs(a - c) + abs(b - d);

  return 0;
}