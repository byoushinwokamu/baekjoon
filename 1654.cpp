#include <algorithm>
#include <iostream>

using namespace std;
long long lancable[10005];

long long k, n;
long long cnt, len, res, ll, rr;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> k >> n;
  for (int i = 0; i < k; i++)
    cin >> lancable[i];
  sort(lancable, lancable + k);
  ll = 1, rr = lancable[k - 1];
  while (ll <= rr) {
    len = (ll + rr) / 2;
    cnt = 0;
    for (int i = 0; i < k; i++)
      cnt += lancable[i] / len;
    if (cnt >= n) {
      res = len;
      ll = len + 1;
    } else
      rr = len - 1;
  }
  cout << res;
  return 0;
}