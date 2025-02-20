// BOJ 1469
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, cur;
vector<char> x;
vector<bool> used;
vector<char> ss;

void dfs(int level) {
  if (level == n) {
    for (auto s : ss)
      cout << s << ' ';
    exit(0);
  }
  for (cur = level; cur < 2 * n && ss[cur] != 0; cur++)
    ;
  if (cur == 2 * n)
    return;

  for (int i = 0; i < n; i++) {
    if (used[i])
      continue;
    ss[cur] = x[i];
    if ((x[i] + cur) >= (2 * n)) {
      cout << cur << " is cur, " << x[i] << " is x[i]\n";
      cout << 2 * n << endl;
      ss[cur] = 0;
      continue;
    }
    cout << "HELP" << endl;

    ss[x[i] + cur] = x[i];
    used[i] = true;
    for (auto s : ss)
      cout << s << ' ';
    cout << endl;
    dfs(level + 1);
    used[i] = false;
    ss[cur] = 0;
    ss[x[i] + cur] = 0;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;

  x.resize(n);
  ss.resize(2 * n);
  used.resize(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  dfs(0);

  cout << -1;
  return 0;
}
