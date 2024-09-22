#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
bool visited[100001];
long long n, m, r, s, f, t; // node, m(arc), r(start), s, f, t(#)
long long res;              // result

void dfs(int now, int d) {
  visited[now] = true;
  res += (++t) * d;
  for (int nex : v[now])
    if (!visited[nex])
      dfs(nex, d + 1);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m >> r;
  for (int i = 0; i < m; i++) {
    cin >> s >> f;
    v[s].push_back(f);
    v[f].push_back(s);
  }
  for (int i = 1; i <= n; i++) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }
  dfs(r, 0);
  cout << res;
}