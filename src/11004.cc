#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, k, t;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  cout << v[k - 1];

  return 0;
}