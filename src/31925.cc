#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<string, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pp> shaker;
  string name, hak, win;
  int s, a;
  while (n--) {
    cin >> name >> hak >> win >> s >> a;
    if (hak == "jaehak" && win == "notyet" && (s > 3 || s == -1))
      shaker.push_back({name, a});
  }
  sort(shaker.begin(), shaker.end(), [](pp a, pp b) { return a.se < b.se; });
  if (shaker.size() > 10)
    shaker.resize(10);
  sort(shaker.begin(), shaker.end(), [](pp a, pp b) { return a.fi < b.fi; });
  cout << shaker.size() << '\n';
  for (auto a : shaker)
    cout << a.fi << '\n';

  return 0;
}
