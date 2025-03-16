// BOJ 2661
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, depth;
string v;

bool isgood() {
  for (int i = depth / 2; i > 0; i--) {
    int badcnt = 0;
    for (int j = depth - 2 * i; j < depth - i; j++) {
      if (v[j] == v[j + i])
        badcnt++;
    }
    if (badcnt == i)
      return false;
  }
  return true;
}

void dfs() {
  if (depth == n) {
    if (isgood()) {
      cout << v;
      exit(0);
    }
    return;
  }

  if (!isgood())
    return;

  for (char c = '1'; c <= '3'; c++) {
    v[depth++] = c;
    dfs();
    depth--;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  v.resize(n);
  dfs();

  return 0;
}
