#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  long long n, m, t;
  cin >> n;
  vector<long long> ti(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> t;
      ti[i] += t;
    }
  }
  sort(ti.begin(), ti.end(), less<int>());
  long long noww = 0;
  long long summ = 0;
  for (auto i : ti) {
    noww += i;
    summ += noww;
  }
  cout << summ;

  return 0;
}