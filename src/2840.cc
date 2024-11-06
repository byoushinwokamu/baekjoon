#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, char> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<char> w(n);
  vector<bool> ch(26);
  int cur = 0;
  int s;
  char c;
  for (int i = 0; i < k; i++) {
    cin >> s >> c;
    cur = (cur + s) % n;
    if (w[cur] != 0 && w[cur] != c) {
      cur = -1;
      break;
    }
    if (ch[c - 'A'] && w[cur] != c) {
      cur = -1;
      break;
    }
    w[cur] = c;
    ch[c - 'A'] = true;
  }
  if (cur == -1)
    cout << '!';
  else {
    for (int i = n; i > 0; i--) {
      if (w[(i + cur) % n])
        cout << w[(i + cur) % n];
      else
        cout << '?';
    }
  }

  return 0;
}
