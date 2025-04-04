// BOJ 2740
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  cin >> m >> k;
  vector<vector<int>> b(m, vector<int>(k));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < k; j++)
      cin >> b[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int s = 0;
      for (int z = 0; z < m; z++)
        s += a[i][z] * b[z][j];
      cout << s << ' ';
    }
    cout << '\n';
  }

  return 0;
}
