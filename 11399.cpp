#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, t;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  int res = 0, i = 1;
  for (auto it = v.rbegin(); it != v.rend(); it++) {
    res += (*it) * (i++);
  }
  cout << res;

  return 0;
}