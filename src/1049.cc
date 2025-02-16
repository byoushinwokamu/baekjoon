// BOJ 1049
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
  int n, m;
  cin >> n >> m;
  int min6 = 1000, min1 = 1000;
  for (int i = 0; i < m; i++) {
    int a6, a1;
    cin >> a6 >> a1;
    min6 = min(min6, a6), min1 = min(min1, a1);
  }
  int r1 = (n / 6 * min6) + (n % 6 * min1);
  int r2 = (n / 6 + 1) * min6;
  int r3 = n * min1;
  cout << min({r1, r2, r3});

  return 0;
}
