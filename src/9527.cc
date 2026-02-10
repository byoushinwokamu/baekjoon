// BOJ 9527
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

ll getn(ll n)
{
  ll cnt = 0;
  ll base = 1;
  while (n >= base)
  {
    if ((n / base) % 2 == 1) cnt += (n % base) + 1 + ((n / base / 2) * base);
    else cnt += (n / base / 2) * base;

    base <<= 1;
  }
  return cnt;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll a, b;
  cin >> a >> b;

  ll cnt = 0;
  cnt += getn(b);
  cnt -= getn(a - 1);
  cout << cnt;

  return 0;
}
