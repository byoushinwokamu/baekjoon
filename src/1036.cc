// BOJ 1036
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

class int36
{
  public:
  int8_t n[55];
  int size;

  int36()
  {
    size = 0;
    fill(n, n + 55, 0);
  }
  int36(string s)
  {
    for (int i = 0; i < s.length(); i++)
    {
      n[i] = *(s.rbegin() + i);
      if (n[i] >= '0' && n[i] <= '9') n[i] -= '0';
      else n[i] += -'A' + 10;
    }
    size = s.length();
  }
  void replaceZ(char c) {}
};

ostream &operator<<(ostream &os, const int36 &bi)
{
  for (int i = bi.size - 1; i >= 0; i--)
  {
    if (bi.n[i] < 10)
      os << (int)bi.n[i];
    else
      os << (char)(bi.n[i] + 'A' - 10);
  }
  return os;
}

int36 operator+(const int36 &a, const int36 &b)
{
  int36 res;
  res.size = max(a.size, b.size);
  for (int i = 0; i < res.size; i++)
  {
    res.n[i] += a.n[i] + b.n[i];
    if (res.n[i] >= 36) res.n[i] -= 36, res.n[i + 1]++;
  }
  if (res.n[res.size]) res.size++;
  return res;
}

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int36 a(s);
  cin >> s;
  int36 b(s);
  cout << a + b;

  return 0;
}
