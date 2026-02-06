// BOJ 2805
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
  cin >> n >> m;
  vector<int> namu(n);
  for (int i = 0; i < n; i++) cin >> namu[i];

  int lft = 0, rht = *max_element(namu.begin(), namu.end()), mid;
  for (mid = (lft + rht) / 2; lft <= rht; mid = (lft + rht) / 2)
  {
    ll s = 0;
    for (auto i : namu) s += (i > mid ? (i - mid) : 0);
    if (s > m) lft = mid + 1;
    else if (s < m) rht = mid - 1;
    else break;
  }
  cout << mid;

  return 0;
}
