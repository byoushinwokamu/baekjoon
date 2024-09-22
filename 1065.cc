#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, cnt = 0;
  char s[5];
  cin >> n;
  n == 1000 ? n-- : n;
  for (int i = 1; i <= n; i++) {
    if (i < 100) {
      cnt++;
      continue;
    }
    sprintf(s, "%d", i);
    if (s[0] - s[1] == s[1] - s[2])
      cnt++;
  }
  cout << cnt;

  return 0;
}