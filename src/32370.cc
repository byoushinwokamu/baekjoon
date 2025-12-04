// BOJ 32370
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

#define MAXPOS (100000000 - 1)

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  pp a, b;
  cin >> a.fi >> a.se >> b.fi >> b.se;
  if (a.fi && a.se)
    cout << 2;
  else if (!a.fi && b.fi)
    cout << 1;
  else if (!a.fi && !b.fi && a.se < b.se)
    cout << 1;
  else if (!a.fi && !b.fi && a.se > b.se)
    cout << 3;
  else if (!a.se && b.se)
    cout << 1;
  else if (!a.se && !b.se && a.fi < b.fi)
    cout << 1;
  else if (!a.se && !b.se && a.fi > b.fi)
    cout << 3;

  return 0;
}
