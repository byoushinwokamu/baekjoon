#include <iostream>
#include <map>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m, i;
  cin >> n;
  map<int, int> mm;
  for (i = 0; i < n; i++) {
    cin >> m;
    mm[m]++;
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> n;
    cout << mm[n] << " ";
  }

  return 0;
}