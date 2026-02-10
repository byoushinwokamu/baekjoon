// BOJ 7677
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
  int a, b, c, d;
} mat22;

mat22 operator*(const mat22 &m1, const mat22 &m2)
{
  mat22 result;
  result.a = m1.a * m2.a + m1.b * m2.c;
  result.a %= 10000;
  result.b = m1.a * m2.b + m1.b * m2.d;
  result.b %= 10000;
  result.c = m1.b * m2.a + m1.d * m2.c;
  result.c %= 10000;
  result.d = m1.b * m2.b + m1.d * m2.d;
  result.d %= 10000;
  return result;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n;

  cin >> n;
  while (n != -1)
  {
    mat22 res = {1, 1, 1, 0};
    ll pw = n;
    mat22 an = res;
    while (pw)
    {
      if (pw % 2) res = res * an;
      an = an * an;
      pw /= 2;
    }
    cout << res.d << '\n';
    cin >> n;
  }

  return 0;
}
