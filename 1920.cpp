#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> m;
    v.push_back(m);
  }
  cin >> m;
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    cin >> n;
    cout << (binary_search(v.begin(), v.end(), n) ? "1" : "0") << '\n';
  }
  return 0;
}