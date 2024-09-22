#include <iostream>

using namespace std;
int n, m;
string s;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> s;
  int cnt = 0;
  int len = 1;
  for (int i = 0; i < m; i++) {
    if (s[i] == 'I') {
      for (i++; i < m; i++) {
        if (s[i] == s[i - 1]) {
          i--;
          break;
        }
        len++;
      }
      if (len >= 2 * n + 1)
        cnt += (len - 1) / 2 - n + 1;
      len = 1;
    }
  }
  cout << cnt;

  return 0;
}