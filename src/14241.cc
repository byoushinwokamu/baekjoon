#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, sc = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int x = v[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sc += x * v[i];
    x += v[i];
  }
  cout << sc;

  return 0;
}