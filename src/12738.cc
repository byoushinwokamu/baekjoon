// BOJ 12738
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
  int a, n;
  cin >> n;

  vector<int> lg(n);
  vector<int> sm(n + 1, 1000000001);

  cin >> a;
  lg[0] = 1;
  sm[1] = a;
  int lgg = 1;
  for (int i = 1; i < n; i++)
  {
    cin >> a;
    lg[i] = lower_bound(sm.begin() + 1, sm.begin() + lgg + 1, a) - sm.begin();
    sm[lg[i]] = min(sm[lg[i]], a);
    lgg = max(lgg, lg[i]);
  }
  cout << lgg;

  return 0;
}
