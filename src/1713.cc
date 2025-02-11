// BOJ 1713
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
typedef pair<int, pp> ppp; // 번호, 추천수, 게시시간

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, cc, p;
  cin >> n >> cc;
  vector<ppp> teul(n);
  int space = n;
  for (int i = 0; i < cc; i++) {
    cin >> p;
    bool found = false;
    for (int j = 0; j < n; j++) {
      if (teul[j].fi == p) {
        teul[j].se.fi++;
        found = true;
        break;
      }
    }
    if (found)
      continue;

    if (space)
      teul[--space] = {p, {1, i}};
    else {
      // find minimum gaechu
      int mink = -1, minc = 1000, mint = 1000;
      for (int k = 0; k < n; k++) {
        auto p = teul[k];
        if (p.se.fi > minc)
          continue;
        if (p.se.fi < minc)
          mink = k, minc = p.se.fi, mint = p.se.se;
        else if (p.se.fi == minc && p.se.se < mint)
          mink = k, mint = p.se.se;
      }
      teul[mink] = {p, {1, i}};
    }
  }
  sort(teul.begin(), teul.end(), [](ppp &a, ppp &b) { return a.fi < b.fi; });
  for (int i = space; i < n; i++)
    cout << teul[i].fi << ' ';

  return 0;
}
