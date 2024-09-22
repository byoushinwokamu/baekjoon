#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v(100001);
long long lsum;
int n, x, y;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    int len = v[i].size();
    if (len <= 1)
      continue;
    sort(v[i].begin(), v[i].end());
    lsum += abs(v[i][0] - v[i][1]);
    for (int j = 1; j < len - 1; j++) {
      lsum += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
    }
    lsum += v[i][len - 1] - v[i][len - 2];
  }
  cout << lsum;

  return 0;
}