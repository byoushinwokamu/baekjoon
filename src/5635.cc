// BOJ 5635
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
  string name;
  int d, m, y;
  vector<pp> v;
  while (n--) {
    cin >> name >> d >> m >> y;
    v.push_back({name, y * 13 * 32 + m * 32 + d});
  }
  sort(v.begin(), v.end(), [](pp &a, pp &b) { return a.se > b.se; });
  cout << ((*v.begin()).fi) << '\n' << ((*v.rbegin()).fi);

  return 0;
}
