// BOJ 32979
#include <algorithm>
#include <deque>
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
  int n, t, cur = 0, b;
  cin >> n >> t;

  vector<int> v(n * 2);
  for (int i = 0; i < 2 * n; i++) cin >> v[i];

  while (t--)
  {
    cin >> b;
    cur += b;
    cur %= n * 2;
    cout << v[cur] << ' ';
  }

  return 0;
}
