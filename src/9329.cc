#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  int n, m, k;
  int sg = 0;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<pair<vector<int>, int>> sg_data(n);
    for (int i = 0; i < n; i++) {
      cin >> k;
      for (int j = 0; j < k; j++) {
        int tem;
        cin >> tem;
        sg_data[i].fi.push_back(tem);
      }
      cin >> sg_data[i].se;
    }
    vector<int> sticker(m);
    for (int i = 0; i < m; i++)
      cin >> sticker[i];

    for (auto sg_line : sg_data) {
      int mins = 100;
      for (auto s : sg_line.fi) {
        mins = min(mins, sticker[s - 1]);
      }
      sg += mins * sg_line.se;
    }
    cout << sg << '\n';
    sg = 0;
  }

  return 0;
}
