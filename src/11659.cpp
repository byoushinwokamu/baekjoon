#include <iostream>

using namespace std;
int sum[100000];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m, a, b, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t;
    sum[i] = (i == 0 ? 0 : sum[i - 1]) + t;
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    cout << sum[b - 1] - (a == 1 ? 0 : sum[a - 2]) << '\n';
  }

  return 0;
}