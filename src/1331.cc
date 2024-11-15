#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<vector<bool>> vis(6, vector<bool>(6));
pp bef, st;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string s;
  for (int i = 0; i < 36; i++) {
    cin >> s;
    if (vis[s[0] - 'A'][s[1] - '1']) { // detect duplicated step
      cout << "Invalid";
      return 0;
    }
    if (i > 0) { // detect invalid step
      int dx = abs(bef.fi - s[0] + 'A');
      int dy = abs(bef.se - s[1] + '1');
      if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1))
        ;
      else {
        cout << "Invalid";
        return 0;
      }
    } else {
      st = {s[0] - 'A', s[1] - '1'};
    }
    bef = {s[0] - 'A', s[1] - '1'};
    vis[bef.fi][bef.se] = true;
  }
  int dx = abs(st.fi - s[0] + 'A');
  int dy = abs(st.se - s[1] + '1');
  if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1))
    cout << "Valid";
  else
    cout << "Invalid";

  return 0;
}
