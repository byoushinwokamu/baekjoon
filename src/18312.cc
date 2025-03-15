// BOJ 18312
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void sec(string &t) {
  bool h = false, m = false;

  if (t[5] == '9') {
    if (t[4] == '5') {
      m = true;
      t[4] = '0', t[5] = '0';
    } else {
      t[4]++, t[5] = '0';
    }
  } else {
    t[5]++;
  }

  if (m) {
    if (t[3] == '9') {
      if (t[2] == '5') {
        h = true;
        t[2] = '0', t[3] = '0';
      } else {
        t[2]++, t[3] = '0';
      }
    } else {
      t[3]++;
    }
  }

  if (h) {
    if (t[1] == '9') {
      t[0]++, t[1] = '0';
    } else {
      t[1]++;
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  n++, k += '0';

  string t = "000000";
  string s(6, '0');
  s[0] = n / 10 + '0', s[1] = n % 10 + '0';

  int cnt = 0;
  while (t != s) {
    bool cc = false;
    for (auto c : t)
      if (c == k)
        cc = true;
    if (cc)
      cnt++;
    sec(t);
  }

  cout << cnt;

  return 0;
}
