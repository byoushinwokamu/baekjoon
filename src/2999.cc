// BOJ 2999
#include <algorithm>
#include <cmath>
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
  int r, c, n, t;
  string s;
  cin >> s;
  n = s.length();

  r = floor(sqrt(n));
  while (n % r) r--;
  c = n / r;
  t = r, r = c, c = t;

  for (int j = 0; j < c; j++)
    for (int i = 0; i < r; i++)
      cout << s[j + i * c];

  return 0;
}
