#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n;
vector<string> col;

int countmax() {
  int cnt = 0;
  int cntmax = 0;
  for (int i = 0; i < n; i++) {
    cnt = 1;
    for (int j = 1; j < n; j++) {
      if (col[i][j] == col[i][j - 1])
        cntmax = max(++cnt, cntmax);
      else
        cnt = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cnt = 1;
    for (int j = 1; j < n; j++) {
      if (col[j][i] == col[j - 1][i])
        cntmax = max(++cnt, cntmax);
      else
        cnt = 1;
    }
  }
  return cntmax;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  col.resize(n);
  for (int i = 0; i < n; i++)
    cin >> col[i];

  int cmax = 0;
  char t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i < n - 1) {
        t = col[i][j];
        col[i][j] = col[i + 1][j];
        col[i + 1][j] = t;
        cmax = max(cmax, countmax());
        t = col[i][j];
        col[i][j] = col[i + 1][j];
        col[i + 1][j] = t;
      }
      if (j < n - 1) {
        t = col[i][j];
        col[i][j] = col[i][j + 1];
        col[i][j + 1] = t;
        cmax = max(cmax, countmax());
        t = col[i][j];
        col[i][j] = col[i][j + 1];
        col[i][j + 1] = t;
      }
    }
  }
  cout << cmax;

  return 0;
}
