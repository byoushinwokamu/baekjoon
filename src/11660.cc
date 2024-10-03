#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define first fi
#define second se
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1, vector<int>(n + 1));
  vector<vector<int>> s(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> v[i][j];
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + v[i][j];
    }
  }
  int x1, y1, x2, y2;
  for (int i = 0; i < m; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
         << '\n';
  }
  return 0;
}