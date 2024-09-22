#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll c(int n, vector<int> r) {
  ll res = 1;
  auto cur = max_element(r.begin(), r.end());
  int nr = *cur;
  for (int i = n; i >= nr; i--)
    res *= i;
  for (auto it = r.begin(); it != r.end(); it++) {
    if (cur == it)
      continue;
    for (int i = *it; i > 0; i--)
      res /= i;
  }

  return res;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int res = 0;
  m -= n;

  return 0;
}