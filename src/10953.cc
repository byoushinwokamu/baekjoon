// BOJ 10953
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
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    cout << (s[0] + s[2] - '0' - '0') << '\n';
  }

  return 0;
}
