// BOJ 14648
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
  int n, q, op, a, b, c, d;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  while (q--) {
    cin >> op >> a >> b;

    if (op == 1) {
      ll s = 0;
      for (int i = a - 1; i < b; i++)
        s += v[i];
      cout << s << '\n';
      int &q = v[a - 1], &w = v[b - 1];
      q = q ^ w, w = q ^ w, q = q ^ w;

    } else if (op == 2) {
      cin >> c >> d;
      ll s = 0;
      for (int i = a - 1; i < b; i++)
        s += v[i];
      for (int i = c - 1; i < d; i++)
        s -= v[i];
      cout << s << '\n';
    }
  }

  return 0;
}
