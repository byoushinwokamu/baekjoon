#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
vector<bool> num('9' + 1);

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  char s[5];
  int n, m;
  cin >> n >> m;
  while (!cin.eof()) {
    int cnt = 0;
    int a;
    for (int i = n; i <= m; i++) {
      fill(num.begin(), num.end(), false);
      sprintf(s, "%d", i);
      bool good = true;
      for (int j = 0; j < strlen(s); j++) {
        if (num[s[j]])
          good = false;
        else
          num[s[j]] = true;
      }
      if (good)
        cnt++;
    }
    cout << cnt << '\n';

    cin >> n >> m;
  }

  return 0;
}
