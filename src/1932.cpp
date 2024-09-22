#include <algorithm>
#include <iostream>

using namespace std;

int maxx[500][500];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cin >> maxx[0][0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> maxx[i][j];
      if (j == 0)
        maxx[i][j] += maxx[i - 1][j];
      else if (j == i)
        maxx[i][j] += maxx[i - 1][j - 1];
      else
        maxx[i][j] += max(maxx[i - 1][j - 1], maxx[i - 1][j]);
    }
  }
  int maxxx = 0;
  for (int i = 0; i < n; i++)
    maxxx = maxxx > maxx[n - 1][i] ? maxxx : maxx[n - 1][i];
  cout << maxxx;

  return 0;
}