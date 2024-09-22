#include <algorithm>
#include <iostream>

using namespace std;

int q, w, e;
int qq, ww, ee;
int a, s, d;
int z, x, c;
int zz, xx, cc;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> s >> d;
    qq = max(q, w) + a;
    ww = max({q, w, e}) + s;
    ee = max(w, e) + d;
    zz = min(z, x) + a;
    xx = min({z, x, c}) + s;
    cc = min(x, c) + d;
    q = qq, w = ww, e = ee, z = zz, x = xx, c = cc;
  }
  cout << max({q, w, e}) << " " << min({z, x, c});

  return 0;
}