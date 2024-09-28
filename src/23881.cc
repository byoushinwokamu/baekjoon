#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, k, t, mxidx, chcnt = 0;
  cin >> n >> k;
  vector<int> v(10000);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (int i = n - 1; i > 0; i--) {
    int m = 0;
    for (int j = i; j >= 0; j--)
      if (m < v[j])
        mxidx = j, m = v[j];
    if (v[i] != m)
      v[mxidx] = v[i], v[i] = m, chcnt++;
    if (chcnt == k) {
      cout << v[mxidx] << ' ' << v[i];
      return 0;
    }
  }
  cout << -1;

  return 0;
}