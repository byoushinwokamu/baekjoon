// BOJ 13976
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

typedef struct
{
  ll a, b, c, d;
} mat22;

constexpr ll md = 1'000'000'007;

mat22 operator*(const mat22 &m1, const mat22 &m2)
{
  mat22 res;
  res.a = (m1.a * m2.a + m1.b * m2.c) % md;
  res.b = (m1.a * m2.b + m1.b * m2.d) % md;
  res.c = (m1.c * m2.a + m1.d * m2.c) % md;
  res.d = (m1.c * m2.b + m1.d * m2.d) % md;
  return res;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

  ll n;
  cin >> n;
  if (n % 2)
  {
    cout << 0;
    return 0;
  }

  // mat22 res = {3, 11, 11, 39};
  // ll pw = n / 2 - 1;
  mat22 res = {1, 3, 3, 11};
  ll pw = n / 2;
  mat22 an = {0, 2, 1, 3};

  while (pw)
  {
    if (pw % 2) res = res * an;
    an = an * an;
    pw /= 2;
  }

  cout << res.a;
  cout << ' ' << res.b << endl
       << res.c << ' ' << res.d;

  return 0;
}
