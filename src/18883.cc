#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n;) {
    for (int j = 1; j < m; j++)
      cout << i * m + j << ' ';
    cout << (++i) * m << '\n';
  }

  return 0;
}