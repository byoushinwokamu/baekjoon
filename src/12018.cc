// BOJ 12018
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m, p, l;
  cin >> n >> m;
  vector<int> cl(n);
  for (int i = 0; i < n; i++) {
    cin >> p >> l;
    vector<int> mil(p);
    for (int j = 0; j < p; j++)
      cin >> mil[j];
    sort(mil.begin(), mil.end(), greater<int>());
    if (p > l)
      cl[i] = mil[l - 1];
    else
      cl[i] = 1;
  }
  sort(cl.begin(), cl.end());
  int ms = 0;
  int i;
  for (i = 0; i < n; i++) {
    cl[i] += cl[i] ? 0 : 1;
    if (ms + cl[i] > m)
      break;
    ms += cl[i];
  }
  cout << i;

  return 0;
}
