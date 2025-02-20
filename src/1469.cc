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

#define EMPTY -1

int n;
vector<int> x;
vector<bool> used;
vector<int> ss;

void dfs(int level) {
  int cur;
  if (level == n) {
    for (auto s : ss)
      cout << s << ' ';
    exit(0);
  }
  for (cur = level; cur < 2 * n && ss[cur] != EMPTY; cur++)
    ;
  if (cur == 2 * n)
    return;

  for (int i = 0; i < n; i++) {
    if (used[i])
      continue;
    ss[cur] = x[i];
    if ((x[i] + cur + 1) >= (2 * n)) {
      ss[cur] = EMPTY;
      continue;
    }
    if (ss[x[i] + cur + 1] != EMPTY) {
      ss[cur] = EMPTY;
      continue;
    }

    ss[x[i] + cur + 1] = x[i];
    used[i] = true;
    // for (auto s : ss)
    //   cout << (s == EMPTY ? '*' : (char)(s + 48)) << ' ';
    // cout << endl;
    dfs(level + 1);
    used[i] = false;
    ss[cur] = EMPTY;
    ss[x[i] + cur + 1] = EMPTY;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;

  x.resize(n);
  ss.resize(2 * n, EMPTY);
  used.resize(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sort(x.begin(), x.end());
  dfs(0);

  cout << -1;
  return 0;
}
