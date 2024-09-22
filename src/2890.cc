#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int r, c;
  cin >> r >> c;
  string s;
  vector<vector<int>> v(c);
  vector<int> ranking(9);
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (auto c = s.begin() + 1; c + 1 != s.end(); c++) {
      if (*c != '.') {
        v[c - s.begin()].push_back(*c - '1');
        break;
      }
    }
  }
  int n = 1;
  for (auto vv = v.rbegin(); vv != v.rend(); vv++) {
    if (!vv->size())
      continue;
    for (auto it : *vv) {
      ranking[it] = n;
    }
    n++;
  }
  for (auto i : ranking)
    cout << i << '\n';
  return 0;
}