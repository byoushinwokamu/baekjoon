// BOJ 11054-1
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
  cin >> n;

  vector<int> a(n);
  vector<int> lg(n); // lis
  vector<int> sm(n + 1, 1001);
  vector<int> lgr(n); // reverse lis: forward lds
  vector<int> smr(n + 1, 1001);

  cin >> a[0];
  int lgg = 1;
  lg[0] = 1;
  sm[1] = a[0];
  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    lg[i] = lower_bound(sm.begin() + 1, sm.begin() + lgg + 1, a[i]) - sm.begin();
    sm[lg[i]] = min(sm[lg[i]], a[i]);
    lgg = max(lgg, lg[i]);
  }

  int lggr = 1;
  lgr[n - 1] = 1;
  smr[1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    lgr[i] = lower_bound(smr.begin() + 1, smr.begin() + lggr + 1, a[i]) - smr.begin();
    smr[lgr[i]] = min(smr[lgr[i]], a[i]);
    lggr = max(lggr, lgr[i]);
  }

  int lmax = 0;
  for (int i = 0; i < n; i++) lmax = max(lmax, lgr[i] + lg[i] - 1);
  cout << lmax;

  return 0;
}
