// BOJ 14469
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
  int n;
  int t = 0;
  int lastn = 0, sum = 0;
  cin >> n;
  vector<pp> cow(n);
  for (int i = 0; i < n; i++)
  {
    cin >> cow[i].fi >> cow[i].se;
    if (cow[lastn].fi < cow[i].fi)
      lastn = i;
    sum += cow[i].se;
  }

  return 0;
}
