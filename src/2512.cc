// BOJ 2512
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
  int n, m;
  cin >> n;
  vector<int> ys(n);
  for (int i = 0; i < n; i++) cin >> ys[i];
  sort(ys.begin(), ys.end());
  cin >> m;

  int lft = 1, rht = ys.back(), mid;
  for (mid = (lft + rht) / 2; lft <= rht; mid = (lft + rht) / 2)
  {
    int s = 0;
    for (auto y : ys) s += min(y, mid);
    if (s < m) lft = mid + 1;
    else if (s > m) rht = mid - 1;
    else break;
  }
  cout << mid;

  return 0;
}
