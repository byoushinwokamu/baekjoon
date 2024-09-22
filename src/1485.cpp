#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  int a, b, c, d, e, f, g, h;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    vector<int> v;
    v.push_back(dist(a, b, c, d));
    v.push_back(dist(c, d, e, f));
    v.push_back(dist(e, f, g, h));
    v.push_back(dist(g, h, a, b));
    v.push_back(dist(a, b, e, f));
    v.push_back(dist(c, d, g, h));
    sort(v.begin(), v.end());
    bool t1 = v[0] == v[1] && v[1] == v[2] && v[2] == v[3];
    bool t2 = v[4] == v[5];
    if (t1 && t2)
      cout << "1\n";
    else
      cout << "0\n";
  }

  return 0;
}