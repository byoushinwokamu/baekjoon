// BOJ 2217
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
  vector<int> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  sort(w.begin(), w.end(), greater<int>());

  int wm = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    wm += w[i];
    if (w[i] * (i + 1) <= wm) ans = max(ans, w[i] * (i + 1));
  }

  cout << ans;

  return 0;
}
