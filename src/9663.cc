// BOJ 9663
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n;
int ver;
int sla;
int bsl;

int ans = 0;

void dfs(int depth, pp st)
{
  if (depth == n)
  {
    ans++;
    return;
  }

  int r = depth;
  for (int c = 0; c < n; c++)
  {
    if (ver & (1 << c) || sla & (1 << (r - c + n)) || bsl & (1 << (r + c))) continue;
    ver |= 1 << c;
    sla |= 1 << (r - c + n);
    bsl |= 1 << (r + c);
    dfs(depth + 1, {r + 1, 0});
    ver &= ~(1 << c);
    sla &= ~(1 << (r - c + n));
    bsl &= ~(1 << (r + c));
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;

  dfs(0, {0, 0});
  cout << ans;

  return 0;
}
