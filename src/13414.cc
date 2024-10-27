#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<string, int> pp;

unordered_map<string, int> msi;
vector<pp> v;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int k, l, c = 0;
  string s;
  cin >> k >> l;
  for (int i = 0; i < l; i++) {
    cin >> s;
    msi[s] = i;
  }

  for (auto &a : msi)
    v.push_back(a);

  sort(v.begin(), v.end(), [](pp a, pp b) -> bool { return a.se < b.se; });

  for (int i = 0; i < min(k, (int)v.size()); i++) {
    cout << v[i].fi << '\n';
  }

  return 0;
}
