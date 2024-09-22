#include <algorithm>
#include <iostream>

using namespace std;

int h[20], c, cc;
int n, b, res = 2100000000;
int sum = 0;

void solve(int top) {
  if (c == cc)
    return;
  for (int i = top; i < n; i++) {
    if (c & (1 << i))
      continue;
    sum += h[i];
    if (sum >= b) {
      res = min(res, sum);
    } else {
      c |= 1 << i;
      solve(i + 1);
      c &= ~(1 << i);
    }
    sum -= h[i];
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    cc |= 1 << i;
  }

  solve(0);
  cout << res - b;
  return 0;
}