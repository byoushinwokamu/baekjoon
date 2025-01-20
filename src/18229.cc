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
  cin >> n >> m >> k;
  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];

  vector<int> hand(n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      hand[j] += v[j][i];
      if (hand[j] >= k) {
        cout << j + 1 << ' ' << i + 1;
        return 0;
      }
    }

  return 0;
}
