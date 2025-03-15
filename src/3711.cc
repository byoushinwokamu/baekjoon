// BOJ 3711
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, g, a;
  cin >> n;
  while (n--) {
    cin >> g;
    vector<int> v(g);
    for (int i = 0; i < g; i++)
      cin >> v[i];
    for (int m = g;; m++) {
      set<int> s;
      for (auto vv : v)
        s.insert(vv % m);
      if (s.size() == g) {
        cout << m << '\n';
        break;
      }
    }
  }

  return 0;
}
