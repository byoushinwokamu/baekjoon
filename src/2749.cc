// BOJ 2749
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

typedef struct {
  ll e[2][2];
} mat22;

const mat22 m1110 = {{{1, 1}, {1, 0}}};
vector<mat22> pow2;
vector<ll> p2;

mat22 operator*(const mat22 &a, const mat22 &b) {
  mat22 res;
  res.e[0][0] = (a.e[0][0] * b.e[0][0] + a.e[0][1] * b.e[1][0]) % 1'000'000;
  res.e[0][1] = (a.e[0][0] * b.e[0][1] + a.e[0][1] * b.e[1][1]) % 1'000'000;
  res.e[1][0] = (a.e[1][0] * b.e[0][0] + a.e[1][1] * b.e[1][0]) % 1'000'000;
  res.e[1][1] = (a.e[1][0] * b.e[0][1] + a.e[1][1] * b.e[1][1]) % 1'000'000;
  return res;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  n--;
  ll i = 1;

  pow2.push_back(m1110);
  p2.push_back(1);

  mat22 res = m1110;
  ll p = 1;
  ll a = 1, b = 2;
  while (i * 2 < n) {
    res = res * res;
    p *= 2;
    i <<= 1;
    pow2.push_back(res);
    p2.push_back(p);
  }
  while (i < n) {
    ll pidx = p2.size() - 1;
    while (p2[pidx] + i > n)
      pidx--;
    res = res * pow2[pidx];
    i += p2[pidx];
  }

  cout << res.e[0][0] % 1'000'000;

  return 0;
}
