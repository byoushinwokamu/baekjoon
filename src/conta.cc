// BOJ conta
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

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < 2 * n; i++)
  {
    for (int j = 1; j < 2 * n - i; j++) cout << ' ';
    cout << '*';
    for (int j = 2 * n - i; j < 2 * n; j++) cout << ' ';

    int a = min(i, 2 * n - i - 1);
    for (int j = 0; j < n - a; j++) cout << ' ';
    cout << '*';
    for (int j = 0; j <= 2 * a; j++) cout << ' ';
    cout << '*';
    for (int j = 0; j < n - a; j++) cout << ' ';

    cout << '\n';
  }

  return 0;
}
