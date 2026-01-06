// BOJ 24910
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <array>
#include <tuple>

#define fi first
#define se second

using namespace std;

typedef long long ll;
// typedef pair<int, int> pp;
typedef array<ll, 11> pp;

ll pptoint(const pp &p, const int n)
{
  ll res = 0;
  for (ll i = 10; i >= 0; i--)
    res += p[i], res *= 11;
  return res;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n, k;
  cin >> n >> k;
  ll seatperaxis = round(pow(n, 10));
  unordered_map<ll, vector<ll>> obsmap;
  vector<pp> obs(k);
  for (int i = 0; i < k; i++)
  {
    for (int d = 0; d < 11; d++)
      cin >> (obs[i])[d];
  }

  return 0;
}
