// BOJ 1806
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, s;
  cin >> n >> s;
  vector<int> v(n);
  int lc = 0, rc = 0;
  int acc = 0;
  int minlen = 100'009;
  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (rc = 0; rc < n; rc++)
  {
    acc += v[rc];
    while (lc <= rc && acc >= s)
    {
      minlen = min(minlen, rc - lc + 1);
      acc -= v[lc++];
    }
  }
  cout << (minlen == 100'009 ? 0 : minlen);

  return 0;
}
