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
  string s, ss;
  int n;
  int c = 0;
  cin >> s >> n;
  while (n--) {
    cin >> ss;
    if (s[0] == ss[0] && s[1] == ss[1] && s[2] == ss[2] && s[3] == ss[3] &&
        s[4] == ss[4])
      c++;
  }
  cout << c;

  return 0;
}
