// BOJ 1904
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
  int n;
  cin >> n;
  vector<ll> v(n + 1);
  v[1] = 1;
  v[2] = 2;
  for (int i = 3; i <= n; i++) {
    v[i] = v[i - 2] + v[i - 1];
    v[i] %= 15746;
  }
  cout << v[n];

  return 0;
}
