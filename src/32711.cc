// BOJ 32711
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
  ll n, a;
  cin >> n;
  ll s = 0;
  bool b1 = false, b2 = false;
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    s += a;
    if (!b1 && !(s & 1))
      b1 = true;
  }
  cin >> a;
  s += a;

  if (s & 1)
    cout << 1;
  else
    cout << (b1 ? 1 : 0);

  return 0;
}
