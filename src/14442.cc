// BOJ 14442
#include <algorithm>
#include <iostream>
#include <queue>
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
  vector<string> vv(n);
  vector<vector<int>> v[k + 1];
  for (int c = 0; c <= k; c++) {
    v[c].resize(n);
    for (int i = 0; i < n; i++)
      v[c][i].resize(m);
  }
  for (int i = 0; i < n; i++)
    cin >> vv[i];

  queue<pp> q;

  return 0;
}
