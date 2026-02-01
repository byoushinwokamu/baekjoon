// BOJ 1365
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
  int n, a, lgg = 1;
  cin >> n;

  vector<int> lg(n);
  vector<int> sm(n + 1, 100001);

  cin >> a;
  lg[0] = 1;
  sm[1] = a;

  for (int i = 1; i < n; i++)
  {
    cin >> a;
    lg[i] = lower_bound(sm.begin() + 1, sm.begin() + lgg + 1, a) - sm.begin();
    sm[lg[i]] = min(sm[lg[i]], a);
    lgg = max(lgg, lg[i]);
  }

  cout << n - lgg;

  return 0;
}
