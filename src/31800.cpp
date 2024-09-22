#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, t;
  vector<int> gg, g, p;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    g.push_back(t);
    gg.push_back(t);
  }
  for (int i = 0; i < n; i++) {
    cin >> t;
    p.push_back(t);
  }
  sort(g.begin(), g.end());
  for (int i = 0; i < n; i++) {
    if (g[n - 1] == gg[i])
      cout << gg[i] - g[n - 2] - p[i] << ' ';
    else
      cout << gg[i] - g[n - 1] - p[i] << ' ';
  }
}