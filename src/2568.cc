// BOJ 2568
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
  int n, a, b;
  vector<pp> bot;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    bot.push_back({a, b});
  }
  sort(bot.begin(), bot.end(), [](const pp &a, const pp &b)
       { return a.fi < b.fi; });

  vector<int> lg(500001);
  vector<int> sm(500002, 500001);
  vector<int> ap(500001);
  int lgg = 1;

  lg[0] = 1, sm[1] = bot[0].se, ap[1] = 1;
  for (int i = 1; i < n; i++)
  {
    lg[i] = lower_bound(sm.begin() + 1, sm.begin() + lgg + 1, bot[i].se) - sm.begin();
    sm[lg[i]] = min(sm[lg[i]], bot[i].se);
    ap[i] = lg[i];
    lgg = max(lg[i], lgg);
  }

  cout << lgg << '\n';

  vector<int> lis_rev;
  vector<int> v_rem;
  int cur = n;
  for (lgg; lgg > 0; lgg--)
  {
    while (ap[--cur] != lgg) v_rem.push_back(ap[cur]);
    lis_rev.push_back(ap[cur]);
  }
  for (auto i : v_rem) cout << i << ' ';
  cout << endl;
  for (auto i : lis_rev) cout << i << ' ';

  return 0;
}
