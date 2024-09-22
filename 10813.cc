#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(1);
  for (int i = 1; i <= n; i++)
    v.push_back(i);
  int i, j;
  for (int k = 0; k < m; k++) {
    cin >> i >> j;
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
  }

  for (int i = 1; i <= n; i++)
    cout << v[i] << ' ';

  return 0;
}