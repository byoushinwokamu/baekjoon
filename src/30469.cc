// BOJ 30469
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<vector<int>> adj(10);
string a, b, s;
int n;

void dfs(int idx) {
  if (idx == n - 1) {
    if (s[n - 2] == b[0]) {
      cout << s << b[1];
      exit(0);
    } else {
      return;
    }
  }
  for (auto a : adj[s[idx - 1] - '0']) {
    s[idx] = a + '0';
    dfs(idx + 1);
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  adj[1] = {1, 3, 7, 9};
  adj[2] = {3, 9};
  adj[3] = {1, 7};
  adj[4] = {1, 3, 7};
  adj[5] = {3, 9};
  adj[6] = {1, 7};
  adj[7] = {1, 3, 9};
  adj[8] = {3, 9};
  adj[9] = {7};
  cin >> a >> b >> n;
  s.resize(n - 1);
  s[0] = a[0], s[1] = a[1];

  dfs(2);
  cout << -1;

  return 0;
}
