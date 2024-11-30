#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int k;
vector<int> s;
vector<int> lotto(6);

void dfs(int depth, int last) {
  if (depth == 6) {
    for (auto l : lotto)
      cout << l << ' ';
    cout << '\n';
    return;
  }
  for (int i = last + 1; i < k; i++) {
    lotto[depth] = s[i];
    dfs(depth + 1, i);
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> k;
  while (k) {
    s.clear();
    s.resize(k);
    for (int i = 0; i < k; i++)
      cin >> s[i];

    dfs(0, -1);
    cout << '\n';
    cin >> k;
  }

  return 0;
}
