// BOJ 1914
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
  bigint(int num)
  {
    size = 0;
    fill(n, n + 10005, 0);
    while (num)
    {
      n[size++] = (int8_t)(num % 10);
      num /= 10;
    }
  }
  bigint(string s)
  {
    fill(n, n + 10005, 0);
    for (int i = 0; i < s.length(); i++)
      n[i] = *(s.rbegin() + i) - '0';
    size = s.length();
  }

  bigint &operator+=(const bigint &bi);
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

bigint &bigint::operator+=(const bigint &bi)
{
  *this = *this + bi;
  return *this;
}

bigint k(1);

void printhanoi(int from, int dest, int mid, int depth)
{
  if (depth == 1)
  {
    cout << from << ' ' << dest << '\n';
  }
  else
  {
    printhanoi(from, mid, dest, depth - 1);
    cout << from << ' ' << dest << '\n';
    printhanoi(mid, dest, from, depth - 1);
  }
}

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 2; i <= n; i++)
    k = k + k + 1;

  cout << k << '\n';
  if (n <= 20)
    printhanoi(1, 3, 2, n);

  return 0;
}
