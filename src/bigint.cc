// bigint library
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

#include <iomanip>
const ll base = 10'000'000'000;
const ll baselen = 10;
class bigint
{
  public:
  ll n[1005];
  int size;

  bigint()
  {
    size = 0;
    fill(n, n + 1005, 0);
  }
  bigint(ll num)
  {
    size = 1;
    fill(n, n + 1005, 0);
    n[0] = num;
  }
  bigint(string s)
  {
    size = 0;
    fill(n, n + 1005, 0);
    for (int i = s.length() - baselen; i + baselen > 0; i -= baselen)
    {
      if (i >= 0)
        n[size++] = stoll(s.substr(i, baselen));
      else
        n[size++] = stoll(s.substr(0, baselen + i));
    }
  }

  bigint &operator+=(const bigint &bi);
  bigint &operator*=(const int m);
};

ostream &operator<<(ostream &os, const bigint &bi)
{
  os << bi.n[bi.size - 1];
  for (int i = bi.size - 2; i >= 0; i--)
    os << setfill('0') << setw(baselen) << bi.n[i];
  return os;
}

bigint operator+(const bigint &a, const bigint &b)
{
  bigint res(a);
  res += b;
  return res;
}

bigint &bigint::operator+=(const bigint &bi)
{
  for (int s = 0; s < size; s++)
  {
    n[s] += bi.n[s];
    if (n[s] >= base) n[s + 1] += 1, n[s] -= base;
  }
  if (n[size]) size++;
  return *this;
}