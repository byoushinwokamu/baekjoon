// BOJ 12910
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
  int n, t, ans = 0;
  cin >> n;
  vector<int> v(51);
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    v[t]++;
  }

  for (int b = 1; b <= 50; b++)
  {
    if (!v[b]) break;
    int buf = 1;
    for (int i = 1; i <= b; i++) buf *= v[i];
    ans += buf;
  }

  cout << ans;

  return 0;
}
