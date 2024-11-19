#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int c = (n + 1) / 2;
  sort(v.begin(), v.end());
  int op = 1;
  for (int i = 0; i < c; i++) {
    op += log2(v[i]);
  }

  cout << op;
  return 0;
}
