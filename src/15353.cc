// BOJ 15353
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

class bigint
{
  public:
  int8_t n[10005];
  int size;

  bigint()
  {
    size = 0;
    fill(n, n + 10005, 0);
  }
  bigint(string s)
  {
    for (int i = 0; i < s.length(); i++)
      n[i] = *(s.rbegin() + i) - '0';
    size = s.length();
  }
};

ostream &operator<<(ostream &os, const bigint &bi)
{
  for (int i = bi.size - 1; i >= 0; i--)
  {
    os << (int)bi.n[i];
  }
  return os;
}

bigint operator+(const bigint &a, const bigint &b)
{
  bigint res;
  res.size = max(a.size, b.size);
  for (int i = 0; i < res.size; i++)
  {
    res.n[i] += a.n[i] + b.n[i];
    if (res.n[i] >= 10) res.n[i] -= 10, res.n[i + 1]++;
  }
  if (res.n[res.size]) res.size++;
  return res;
}

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  bigint a(s);
  cin >> s;
  bigint b(s);
  cout << a + b;

  return 0;
}
