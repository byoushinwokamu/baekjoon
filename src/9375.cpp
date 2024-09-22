#include <iostream>
#include <map>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  int n;
  string sn, st;
  for (int tt = 0; tt < t; tt++) {
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
      cin >> sn >> st;
      m[st]++;
    }
    int res = 1;
    for (auto i : m)
      res *= (i.second + 1);
    cout << res - 1 << '\n';
  }

  return 0;
}