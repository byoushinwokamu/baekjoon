// BOJ 1564
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
  int n;
  cin >> n;

  ll f = 1;
  for (int i = 1; i <= n; i++) {
    f *= i;
    while (f % 10 == 0)
      f /= 10;
    f %= 1'000'000'000'000;
  }
  f %= 100000;
  if (f / 10 == 0)
    cout << 0;
  if (f / 100 == 0)
    cout << 0;
  if (f / 1000 == 0)
    cout << 0;
  if (f / 10000 == 0)
    cout << 0;
  cout << f;

  return 0;
}
