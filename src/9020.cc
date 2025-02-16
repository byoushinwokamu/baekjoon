// BOJ 9020
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> inp(10001); // is not prime

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 2; i <= 10000; i++) {
    if (inp[i])
      continue;
    for (int j = 2; i * j <= 10000; j++)
      inp[i * j] = true;
  }

  while (t--) {
    int n;
    cin >> n;
    for (int i = n / 2; i > 1; i--)
      if (!inp[i] && !inp[n - i]) {
        cout << i << ' ' << n - i << '\n';
        break;
      }
  }

  return 0;
}
