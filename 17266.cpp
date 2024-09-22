#include <iostream>
#include <vector>

using namespace std;

int n, m, x, pre, maxl;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  cin >> x;
  maxl = x * 2;
  for (int i = 1; i < m; i++) {
    pre = x;
    cin >> x;
    maxl = max(maxl, x - pre);
  }
  maxl = max(maxl, (n - x) * 2);
  cout << (maxl - 1) / 2 + 1;

  return 0;
}