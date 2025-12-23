// BOJ 1068
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, p;
int cnt = 0;
vector<vector<int>> adj;

void dfs(int now)
{
  if (adj[now].size() == 0)
  {
    cnt++;
    return;
  }
  for (auto i : adj[now])
    dfs(i);
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  adj.resize(n);

  for (int i = 0; i < n; i++)
  {
    cin >> p;
    if (p != -1)
      adj[p].push_back(i);
  }

  cin >> n;
  dfs(n);
  int leaf = 0;
  for (auto v : adj)
  {
    if (v.size() == 0 || (v.size() == 1 && v[0] == n))
      leaf++;
  }
  cout << leaf - cnt;

  return 0;
}
