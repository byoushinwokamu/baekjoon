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
  int n, k;
  cin >> n >> k;
  int a, b;
  cin >> a;
  int c = 0, d = 0;
  for (int i = 1; i < n; i++)
    cin >> b, c += b - a, d += (a == b ? 0 : 1);
  cout << c << ' ' << d;

  return 0;
}
