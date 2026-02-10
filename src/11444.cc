// BOJ 11444
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

constexpr ll md = 1'000'000'007;

// [a b
//  c d]
typedef struct
{
  ll a, b, c, d;
} mat22;

mat22 operator*(const mat22 &m1, const mat22 &m2)
{
  mat22 res;
  res.a = (m1.a * m2.a + m1.b * m2.c) % md;
  res.b = (m1.a * m2.b + m1.b * m2.d) % md;
  res.c = (m1.c * m2.a + m1.d * m2.b) % md;
  res.d = (m1.c * m2.b + m1.d * m2.d) % md;
  return res;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n;
  cin >> n;

  mat22 f0f1 = {0, 1, 1, 1};
  mat22 res = {0, 1, 1, 1};
  mat22 an = f0f1;
  ll pw = n;

  while (pw)
  {
    if (pw % 2) res = res * an;
    an = an * an;
    pw /= 2;
  }

  cout << res.a;

  return 0;
}
