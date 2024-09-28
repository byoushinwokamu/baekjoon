#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t, n, a;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
      cin >> a, v.push_back(a);
    while (n > 2) {
      for (int i = 0; i < n / 2; i++) {
        v[i] += v[n - i - 1];
      }
      if (n % 2)
        v[n / 2] *= 2;
      n++;
      n /= 2;
    }
    cout << "Case #" << tt << ": ";
    cout << (v[0] > v[1] ? "Alice\n" : "Bob\n");
  }

  return 0;
}