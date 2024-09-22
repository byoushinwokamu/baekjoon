#include <iostream>

using namespace std;
bool a[8000][4000];
int n, n2;

void solve(int x, int y, int d) {
  if (d == 3) {
    a[x + 2][y + 1] = true;
    return;
  }
  int i, ii, j;
  int jj = d - 1;
  for (j = d / 2; j <= jj; j++) {
    ii = d * 2 - j - 1;
    for (i = j; i < ii; i++)
      a[x + i][y + j] = true;
  }
  solve(x + d / 2, y, d / 2);
  solve(x, y + d / 2, d / 2);
  solve(x + d, y + d / 2, d / 2);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  n2 = n * 2;

  solve(0, 0, n);
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n - j - 1; i++)
      a[i][j] = true;
    for (int i = n2 - 1; i >= n + j; i--)
      a[i][j] = true;
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n2 - 1; i++)
      cout << (a[i][j] ? ' ' : '*');
    cout << '\n';
  }

  return 0;
}