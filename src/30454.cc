#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, l;
  string s;
  cin >> n >> l;
  int maxline = 0;
  int maxn = 0;

  for (int i = 0; i < n; i++) {
    int lin = 0;
    cin >> s;
    if (s[0] == '1')
      lin++;
    for (int j = 1; j < l; j++) {
      if (s[j - 1] == '0' && s[j] == '1')
        lin++;
    }
    if (maxline == lin)
      maxn++;
    else if (maxline < lin)
      maxline = lin, maxn = 1;
  }
  cout << maxline << ' ' << maxn;

  return 0;
}