// BOJ 1629
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
  int a, b, c;
  cin >> a >> b >> c;

  ll an = a, pw = b, md = c;
  ll res = 1;
  while (pw)
  {
    if (pw % 2) res = res * an % md;
    an = an * an % md;
    pw /= 2;
  }
  cout << res;

  return 0;
}
