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
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int cnt = 0;
    for (int i = 1; i <= a; i++)
      for (int j = 1; j <= b; j++)
        for (int k = 1; k <= c; k++)
          if (i % j == j % k && j % k == k % i)
            cnt++;
    cout << cnt << '\n';
  }

  return 0;
}
