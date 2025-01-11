#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

ll n, a, b;
int gs[11] = {0, 1, 3, 6, 10, 15, 21, 28, 35, 45, 55};
int md = 60;

ll rotate(ll z, ll n, ll o) {
  ll x = 0;
  for (int i = 0; i < 3 * (n - 1); i++)
    x |= (z & (1 << i) ? (1 << (i + 1)) : 0);
  if (n > 3)
    x = rotate(x, n - 3, o + 3 * (n - 1));
  return x;
}

ll mirror(ll z, ll n, ll o) {
  ll x = 0;
  for (int i = 0; i < 3 * (n - 1); i++)
    x |= (z & (1 << i) ? (1 << (3 * n - i - 4)) : 0);
  if (n > 3)
    x = mirror(x, n - 3, o + 3 * (n - 1));
  return x;
}

void diff() {
  ll d = a ^ b;
  int dd = 0;
  for (int i = gs[n] - 1; i >= 0; i--)
    (d & (1 << i)) ? dd++ : dd;
  md = min(md, dd);
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  int t;
  for (int i = 0; i < gs[n]; i++) {
    cin >> t;
    a <<= 1, a += t;
  }
  for (int i = 0; i < gs[n]; i++) {
    cin >> t;
    b <<= 1, b += t;
  }
  cout << a << ' ' << b << endl;
  diff();
  a = rotate(a, n, 0);
  diff();
  a = rotate(a, n, 0);
  diff();
  a = rotate(a, n, 0);
  a = mirror(a, n, 0);
  diff();
  a = rotate(a, n, 0);
  diff();
  a = rotate(a, n, 0);
  diff();
  cout << md;

  return 0;
}
